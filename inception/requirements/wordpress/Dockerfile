# Utiliser Debian comme base
FROM debian:latest

# Installer PHP, PHP-FPM et les extensions nécessaires pour WordPress
RUN apt update && apt install -y \
    php-fpm \
    php-mysql \
    php-xml \
    php-mbstring \
    wget \
    unzip \
    && apt clean

# Télécharger et configurer WordPress
WORKDIR /var/www/html
RUN wget https://wordpress.org/latest.zip && unzip latest.zip && \
    mv wordpress/* . && rm -rf wordpress latest.zip

# Ajuster les permissions
RUN chown -R www-data:www-data /var/www/html

# Exposer le port par défaut de PHP-FPM
EXPOSE 9000

# Commande pour démarrer PHP-FPM
CMD ["php-fpm", "-F"]
