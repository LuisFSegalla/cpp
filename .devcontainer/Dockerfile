ARG VER=22.04
FROM ubuntu:${VER} AS build
USER root

# Install needed packages. Use a separate RUN statement to add your own dependencies.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install build-essential \
    cmake cppcheck valgrind clang lldb\
     llvm gdb libcurlpp-dev \
     libjsoncpp-dev libsqlite3-dev \
     pkg-config nlohmann-json3-dev&& \
     apt-get -y clean all
