FROM ubuntu:latest    

WORKDIR /usr/src/app

RUN apt update
RUN apt -yq install g++ cmake
