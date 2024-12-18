FROM debian:latest

RUN apt update && apt upgrade -y && apt install -y php-fpm php-mysqli curl mariadb-client

# Copy the www.conf file into the container
COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf

# Download and install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Copy the entrypoint script into the container
COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

CMD ["php-fpm8.2", "-F"]