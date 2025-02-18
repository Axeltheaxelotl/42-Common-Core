#!/bin/bash
cd /var/www/html

# Vérifier la connexion à la base de données
until mysql -h ${WORDPRESS_DB_HOST} -u ${WORDPRESS_DB_USER} -p${WORDPRESS_DB_PASSWORD} -e "SHOW DATABASES;" > /dev/null 2>&1; do
  echo "Waiting for database connection..."
  echo "Host: ${WORDPRESS_DB_HOST}, User: ${WORDPRESS_DB_USER}, Password: ${WORDPRESS_DB_PASSWORD}"
  sleep 5
done

if [ ! -f wp-config.php ]; then
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    ./wp-cli.phar core download --allow-root
    ./wp-cli.phar config create --dbname=${WORDPRESS_DB_NAME} --dbuser=${WORDPRESS_DB_USER} --dbpass=${WORDPRESS_DB_PASSWORD} --dbhost=${WORDPRESS_DB_HOST} --allow-root
    ./wp-cli.phar core install --url=${DOMAIN_NAME} --title=inception --admin_user=admin_user --admin_password=admin_password --admin_email=admin@admin.com --allow-root
else
    echo "WordPress is already installed."
fi

# Ensure wp-cli.phar is present
if [ ! -f wp-cli.phar ]; then
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
fi

php-fpm7.4 -F