FROM debian

RUN apt-get update && apt-get upgrade -y && apt-get install -y sudo build-essential zlib1g-dev libyaml-dev libssl-dev libgdbm-dev libre2-dev libreadline-dev libncurses5-dev libffi-dev curl openssh-server checkinstall libxml2-dev libxslt-dev libcurl4-openssl-dev libicu-dev logrotate rsync python-docutils pkg-config cmake git-core
RUN mkdir /tmp/ruby && cd /tmp/ruby
RUN curl --remote-name --progress https://cache.ruby-lang.org/pub/ruby/2.4/ruby-2.4.3.tar.gz
RUN echo 'fd0375582c92045aa7d31854e724471fb469e11a4b08ff334d39052ccaaa3a98  ruby-2.4.3.tar.gz' | shasum -c - && tar xzf ruby-2.4.3.tar.gz
WORKDIR ruby-2.4.3

RUN ./configure --disable-install-rdoc
RUN make
RUN make install
RUN gem install bundler

RUN curl --remote-name --progress https://storage.googleapis.com/golang/go1.8.3.linux-amd64.tar.gz
RUN echo '1862f4c3d3907e59b04a757cfda0ea7aa9ef39274af99a784f5be843c80c6772  go1.8.3.linux-amd64.tar.gz' | shasum -a256 -c - && tar -C /usr/local -xzf go1.8.3.linux-amd64.tar.gz
RUN ln -sf /usr/local/go/bin/go /usr/local/bin/ && sudo ln -sf /usr/local/go/bin/godoc /usr/local/bin/ && sudo ln -sf /usr/local/go/bin/gofmt /usr/local/bin/
RUN rm go1.8.3.linux-amd64.tar.gz

RUN curl --location https://deb.nodesource.com/setup_8.x | sudo bash -
RUN sudo apt-get install -y nodejs
RUN curl -s --show-error https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
RUN apt-get update && apt-get install -y yarn

RUN adduser --disabled-login --gecos 'GitLab' git

RUN apt-get install -y postgresql postgresql-client libpq-dev postgresql-contrib
RUN service postgresql start && sudo -u postgres psql -d template1 -c "CREATE USER git WITH PASSWORD 'prout' CREATEDB;" && sudo -u postgres psql -d template1 -c "CREATE EXTENSION IF NOT EXISTS pg_trgm;" && sudo -u postgres psql -d template1 -c "CREATE DATABASE gitlabhq_production OWNER git;" && echo "SELECT true AS enabled\nFROM pg_available_extensions\nWHERE name = 'pg_trgm'\nAND installed_version IS NOT NULL;" | sudo -u git -H psql -d gitlabhq_production

RUN apt-get install -y redis-server
COPY --chown=redis:redis ./redis.conf /etc/redis/redis.conf
WORKDIR /home/git
RUN sudo -u git -H git clone https://gitlab.com/gitlab-org/gitlab-ce.git -b 10-1-stable gitlab

WORKDIR /home/git/gitlab/
COPY --chown=git:git ./gitlab.yml ./config

RUN sudo -u git -H cp config/secrets.yml.example config/secrets.yml && sudo -u git -H chmod 0600 config/secrets.yml && sudo chown -R git log && sudo chown -R git tmp && sudo chmod -R u+rwX,go-w log && sudo chmod -R u+rwX tmp && sudo chmod -R u+rwX tmp/pids/ && sudo chmod -R u+rwX tmp/sockets/ && sudo -u git -H mkdir public/uploads/ && sudo chmod 0700 public/uploads && sudo chmod -R u+rwX builds/ && sudo chmod -R u+rwX shared/artifacts/ && sudo chmod -R ug+rwX shared/pages/ && sudo -u git -H cp config/unicorn.rb.example config/unicorn.rb

RUN sudo -u git -H cp config/initializers/rack_attack.rb.example config/initializers/rack_attack.rb && sudo -u git -H git config --global core.autocrlf input && sudo -u git -H git config --global gc.auto 0 && sudo -u git -H git config --global repack.writeBitmaps true && sudo -u git -H git config --global receive.advertisePushOptions true && sudo -u git -H cp config/resque.yml.example config/resque.yml

RUN sudo -u git cp config/database.yml.postgresql config/database.yml
COPY --chown=git:git ./database.yml ./config
RUN sudo -u git -H chmod o-rwx config/database.yml
RUN sudo -u git -H bundle install --deployment --without development test mysql aws kerberos
RUN service redis-server start && sudo -u git -H bundle exec rake gitlab:shell:install REDIS_URL=unix:/var/run/redis/redis.sock RAILS_ENV=production SKIP_STORAGE_VALIDATION=true
RUN sudo -u git -H bundle exec rake "gitlab:workhorse:install[/home/git/gitlab-workhorse]" RAILS_ENV=production
RUN service postgresql start && service redis-server start && echo "yes" | sudo -u git -H bundle exec rake gitlab:setup RAILS_ENV=production
RUN sudo cp lib/support/init.d/gitlab /etc/init.d/gitlab && sudo update-rc.d gitlab defaults 21
RUN service postgresql start && service redis-server start && sudo -u git -H bundle exec rake "gitlab:gitaly:install[/home/git/gitaly]" RAILS_ENV=production && sudo chmod 0700 /home/git/gitlab/tmp/sockets/private && sudo chown git /home/git/gitlab/tmp/sockets/private && sudo cp lib/support/logrotate/gitlab /etc/logrotate.d/gitlab && sudo -u git -H bundle exec rake gitlab:env:info RAILS_ENV=production
RUN sudo -u git -H bundle exec rake gettext:compile RAILS_ENV=production && sudo -u git -H yarn install --production --pure-lockfile && sudo -u git -H bundle exec rake gitlab:assets:compile RAILS_ENV=production NODE_ENV=production
RUN service postgresql start && service redis-server start && sudo service gitlab start && echo "deb http://nginx.org/packages/debian/ stretch nginx" >> /etc/apt/sources.list && echo "deb-src http://nginx.org/packages/debian/ stretch nginx" >> /etc/apt/sources.list && apt-get update && sudo apt-get install -y --allow-unauthenticated nginx
COPY ./gitlab-ssl /etc/nginx/conf.d/gitlab-ssl.conf
COPY ./config.yml /home/git/gitlab-shell/config.yml
RUN mkdir -p /etc/nginx/ssl/ && cd /etc/nginx/ssl/ && yes ye | sudo openssl req -newkey rsa:2048 -x509 -nodes -days 3560 -out gitlab.crt -keyout gitlab.key && sudo chmod o-r gitlab.key

RUN rm /etc/nginx/conf.d/default.conf && service postgresql start && service redis-server start && service gitlab start && service nginx start  &&  mkdir ~/gitlab-check-backup-1531743619 && sudo mv /home/git/.ssh/environment ~/gitlab-check-backup-1531743619 && sudo chmod -R ug+rwX,o-rwx /home/git/repositories && sudo chmod -R ug-s /home/git/repositories && sudo find /home/git/repositories -type d -print0 | sudo xargs -0 chmod g+s && sudo -u git -H bundle exec rake gitlab:check RAILS_ENV=production 

COPY ./server.sh /server.sh
RUN chmod 755 /server.sh
ENTRYPOINT sh /server.sh

EXPOSE 443
EXPOSE 80
EXPOSE 2222

