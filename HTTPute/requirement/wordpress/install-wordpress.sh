#!/bin/bash
set -e

echo "Attente de la disponibilité de MariaDB..."
while ! mysqladmin ping -h mariadb --silent; do
  sleep 1
done
echo "MariaDB est disponible."

cd /var/www/html

if [ -f wp-config.php ]; then
  echo "WordPress est déjà installé."
else
  # Optionnel : nettoyer le répertoire s'il contient des fichiers indésirables
  rm -rf * 2>/dev/null

  curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
  chmod +x wp-cli.phar
  ./wp-cli.phar core download --allow-root --force
  ./wp-cli.phar config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --allow-root
  ./wp-cli.phar core install --url=$DOMAIN_NAME --title=Inception --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --allow-root
fi

php-fpm8.2 -F