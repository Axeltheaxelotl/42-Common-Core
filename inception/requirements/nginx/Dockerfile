# Utiliser Debian comme base
FROM debian:latest

# Installer NGINX
RUN apt update && apt install -y nginx && apt clean

# Copier un fichier de configuration NGINX personnalisé
COPY default.conf /etc/nginx/conf.d/

# Exposer le port HTTP
EXPOSE 80

# Commande pour démarrer NGINX
CMD ["nginx", "-g", "daemon off;"]