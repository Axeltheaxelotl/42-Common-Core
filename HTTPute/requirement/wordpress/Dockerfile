FROM debian:bullseye

# Installation des dépendances et du dépôt Sury pour PHP 8.2
RUN apt update && apt install -y lsb-release ca-certificates apt-transport-https software-properties-common wget \
    && wget -O /etc/apt/trusted.gpg.d/sury-keyring.gpg https://packages.sury.org/php/apt.gpg \
    && echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/sury-php.list \
    && apt update && apt install -y php8.2 php8.2-fpm php8.2-mysql curl \
    && mkdir -p /run/php

# Dossier de travail
WORKDIR /var/www/html

# Démarrer PHP-FPM en mode foreground
CMD ["php-fpm8.2", "-F"]

