FROM debian:buster

RUN apt update -y 

RUN apt install php-fpm php-mysql -y

RUN apt install curl -y

COPY ./conf/script.sh /
COPY ./conf/wp-config.php /

CMD [ "/script.sh" ]