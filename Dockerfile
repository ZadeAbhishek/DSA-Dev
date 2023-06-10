FROM ubuntu:22.04

RUN apt-get -y update && DEBIAN_FRONTEND=noninteractive apt-get install -y -V tzdata
RUN apt-get install -y vim build-essential git cmake net-tools gdb clang

WORKDIR /work