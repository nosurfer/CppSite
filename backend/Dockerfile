FROM alpine:latest
RUN apk add --no-cache \
    python3 \
    py3-pip \
    bash \
    cmake \
    git \
    build-base \
    sqlite \
    sqlite-dev \
    boost-dev \
    asio-dev

WORKDIR /app
COPY . .
RUN chmod +x ./install.sh
CMD ["./install.sh"]
