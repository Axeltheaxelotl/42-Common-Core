#!/bin/bash

cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
./wp-cli.phar core download --allow-root
./wp-cli.phar config create --dbname=WordFumer --dbuser=wpuser --dbpass=mot_de_passe --dbhost=mariadb --allow-root
./wp-cli.phar core install --url=localhost --title=Inception --admin_user=admin --admin_password=admin --admin_email=admin@example.com --allow-root

php-fpm8.2 -F