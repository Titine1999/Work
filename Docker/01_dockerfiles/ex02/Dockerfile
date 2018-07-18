FROM ruby

RUN apt-get update && apt-get install -y nodejs
RUN gem install rails
ONBUILD COPY . /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD RUN bundle install
ONBUILD RUN exec rake db:migrate && rake db:seed
