FROM java

WORKDIR /app

RUN wget -O minecraft_server.1.12.2.jar https://launcher.mojang.com/mc/game/1.12.2/server/886945bfb2b978778c3a0288fd7fab09d315b25f/server.jar

RUN echo "eula=true" > eula.txt

ENTRYPOINT java -Xmx1024M -Xms1024M -jar minecraft_server.1.12.2.jar nogui

EXPOSE 25565
EXPOSE 25565/udp
