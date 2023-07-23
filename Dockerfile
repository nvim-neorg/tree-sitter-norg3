FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get upgrade --yes
RUN apt-get install curl build-essential --yes
# RUN apt-get node
RUN apt-get install graphviz --yes
# RUN apt-get install npm --yes
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y

ENV PATH="/root/.cargo/bin:${PATH}"
ENV USER=root
RUN cargo install tree-sitter-cli

WORKDIR /code

COPY . .
