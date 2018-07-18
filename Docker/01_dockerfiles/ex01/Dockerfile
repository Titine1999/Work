FROM debian
RUN apt-get update && apt-get install -y curl bzip2
WORKDIR /opt
RUN curl http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2 -o quelquechose.tar.bz2
RUN tar -xjf quelquechose.tar.bz2
WORKDIR teamspeak3-server_linux_amd64
EXPOSE 9987/udp
EXPOSE 10011
EXPOSE 30033 
CMD ./ts3server_minimal_runscript.sh
