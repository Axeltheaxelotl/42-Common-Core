# dedian:bullseye
FROM    debian:buster

RUN     apt-get update && apt-get upgrade -y && apt-get install -y nginx openssl

COPY    ./conf/default.conf /etc/nginx/sites-available/default

RUN     openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
                -keyout /etc/ssl/private/nginx-selfsigned.key \
                -out /etc/ssl/certs/nginx-selfsigned.crt \
                -subj "/C=LU/L=LU/O=LU/OU=LU/CN=alanty.42.fr"

EXPOSE  443

ENTRYPOINT ["nginx", "-g", "daemon off;"]