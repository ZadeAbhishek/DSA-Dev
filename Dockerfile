FROM ubuntu:22.04

RUN apt-get -y update && DEBIAN_FRONTEND=noninteractive apt-get install -y -V tzdata
RUN apt-get install -y vim build-essential git cmake net-tools gdb clang
RUN apt install -y nodejs
RUN apt install -y npm
RUN git clone https://github.com/ZadeAbhishek/DSA-Dev.git

WORKDIR /DSA-Dev

ADD . .

RUN npm install -y



