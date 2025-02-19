FROM debian:bullseye

RUN apt update && \
    apt upgrade && \
    apt -y install mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/
COPY init.sql /etc/mysql/init.sql

RUN mkdir /run/mysqld

CMD ["mysqld"]