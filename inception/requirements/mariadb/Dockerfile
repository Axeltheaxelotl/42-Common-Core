FROM debian:latest

RUN apt update && apt upgrade -y && apt install -y mariadb-server

# Copy the custom configuration file into the container
COPY 50-server.cnf /etc/mysql/mariadb.conf.d/
COPY init.sql /etc/mysql/

RUN mkdir -p /run/mysqld /var/lib/mysql && \
    chown -R mysql:mysql /run/mysqld /var/lib/mysql && \
    chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf

USER mysql

CMD ["mysqld"]