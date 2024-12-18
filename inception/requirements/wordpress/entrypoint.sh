#!/bin/bash

# Attendre que MariaDB soit prêt
until mysql -h mariadb -u wpuser -ppassword -e "SHOW DATABASES;" > /dev/null 2>&1; do
  echo "Waiting for MariaDB to be ready..."
  sleep 5
done

# Installer WordPress
cd /var/www/html
wp core download --allow-root
wp config create --dbname=wordpress --dbuser=wpuser --dbpass=password --dbhost=mariadb --allow-root
wp core install --url=localhost --title=inception --admin_user=admin --admin_password=admin --admin_email=admin@example.com --allow-root

# Démarrer PHP-FPM
php-fpm8.2 -F
