FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/
COPY init.sql /etc/mysql/init.sql
COPY script.sh /usr/local/bin/script.sh

RUN chmod +x /usr/local/bin/script.sh && mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

CMD ["/usr/local/bin/script.sh"]