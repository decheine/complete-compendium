# FROM ubuntu:20.04
FROM ubuntu:22.04
LABEL Description="Monster Harvester Build Environment" Version="0.1"

ENV HOME=/root

SHELL ["/bin/bash", "-c"]

# RUN export DEBIAN_FRONTEND="noninteractive"
RUN apt-get clean

RUN apt-get -y update 
RUN DEBIAN_FRONTEND=noninteractive apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    git \
    gdb \
    wget

# Get ca-certs
RUN apt-get install -y ca-certificates

# Set git config
RUN git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt

# RUN apt-get -y install cmake=3.16.3-1ubuntu1 

# Copy the folders /cmm, /harvester, /include, /src into the container
ADD harvester/cmm /usr/local/harvester/cmm
ADD harvester/harvester /usr/local/harvester/harvester
ADD harvester/include /usr/local/harvester/include
ADD harvester/src /usr/local/harvester/src
ADD /data /usr/local/harvester/data
# ADD data /usr/local/harvester/data
ADD harvester/CMakeLists.txt /usr/local/harvester/CMakeLists.txt

# Build the harvester
WORKDIR /usr/local/harvester
RUN mkdir build
WORKDIR /usr/local/harvester/build
# RUN rm CMakeCache.txt
# RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN cmake .. 
RUN cmake --build ./

# Run the harvester
WORKDIR /usr/local/harvester/build
# CMD ["./LomionReader"]
RUN ./bin/LomionReader