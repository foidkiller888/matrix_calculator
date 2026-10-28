
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    libgtest-dev \
    doxygen \
    graphviz \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug \
    && cmake --build build

CMD ["./build/matrix_calculator"]
