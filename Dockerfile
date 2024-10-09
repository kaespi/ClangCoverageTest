FROM ubuntu:22.04

ARG USERNAME=user
ARG USER_UID=10000
ARG USER_GID=10001

RUN apt-get update -y \
    && apt-get install -y wget lsb-release software-properties-common cmake ninja-build catch2

WORKDIR /pkg_installation

# install Clang-17 and Clang-18
# (LLVM snapshot packages)
RUN wget https://apt.llvm.org/llvm.sh
RUN chmod u+x llvm.sh

RUN ./llvm.sh 17
RUN ./llvm.sh 18

# choose Clang-17 as default
ENV CXX=clang++-17

RUN apt-get update -y \
    && apt-get install -y \
        clang-17 clang-18 clang-tidy-17 clang-format-17 clang-tidy-18 clang-format-18

RUN groupadd --gid ${USER_GID} ${USERNAME} \
    && useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} -s /usr/bin/bash

USER ${USERNAME}
WORKDIR /home/user
