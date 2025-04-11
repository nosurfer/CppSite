#!/bin/sh
rm -f /etc/nginx/conf.d/default.conf
openssl req -x509 -days 365 -nodes -newkey rsa:2048 \
        -subj /CN=examle/C=RU/ST=example/O=example \
        -keyout ./vulnerable.com.key -text -out ./vulnerable.com.crt
nginx -t
exec nginx -g 'daemon off;'
