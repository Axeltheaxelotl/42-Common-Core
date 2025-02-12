FROM debian:bullseye

RUN apt update && \
    apt -y upgrade && \
    apt -y install php7.4-fpm \
    php7.4-mysql \
    curl

RUN mkdir -p /run/php

COPY www.conf /etc/php/7.4/fpm/pool.d/
COPY install_wordpress.sh /install_wordpress.sh

RUN chmod +x /install_wordpress.sh

CMD ["./install_wordpress.sh"]