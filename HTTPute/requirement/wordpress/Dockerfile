FROM debian:bullseye

# Installation des dépendances, incluant le client MySQL pour mysqladmin, et du dépôt Sury pour PHP 8.2
RUN apt update && apt install -y lsb-release ca-certificates apt-transport-https software-properties-common wget default-mysql-client \
    && wget -O /etc/apt/trusted.gpg.d/sury-keyring.gpg https://packages.sury.org/php/apt.gpg \
    && echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/sury-php.list \
    && apt update && apt install -y php8.2 php8.2-fpm php8.2-mysql php8.2-mysqli curl \
    && mkdir -p /run/php

# Dossier de travail
WORKDIR /var/www/html

COPY www.conf /etc/php/8.2/fpm/pool.d
COPY install-wordpress.sh /usr/local/bin/install-wordpress.sh

RUN chmod +x /usr/local/bin/install-wordpress.sh

# Démarrer le script d'installation de WordPress
CMD ["/usr/local/bin/install-wordpress.sh"]