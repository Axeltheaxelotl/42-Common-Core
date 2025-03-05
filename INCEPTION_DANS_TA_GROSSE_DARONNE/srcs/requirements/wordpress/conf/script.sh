#!/bin/bash

# create directory to use in nginx container later and also to setup the wordpress conf
mkdir /var/www/
mkdir /var/www/html

cd /var/www/html


rm -rf *

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 

chmod +x wp-cli.phar 

mv wp-cli.phar /usr/local/bin/wp


wp core download --allow-root

mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

mv /wp-config.php /var/www/html/wp-config.php


sed -i -r "s/db1/wordpress/1"   wp-config.php
sed -i -r "s/user/$SQL_USR/1"  wp-config.php
sed -i -r "s/pwd/$SQL_PASSW/1"    wp-config.php

wp core install --url="alanty.42.fr"/ --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PASSW --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

wp user create $WP_NORMAL_USR $WP_NORMAL_EMAIL --role=author --user_pass=$WP_NORMAL_PASSW --allow-root

wp theme install envo-royal --activate --allow-root

wp plugin update --all --allow-root

wp shuffle-salts --allow-root

 
sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf

mkdir /run/php

/usr/sbin/php-fpm7.3 -F