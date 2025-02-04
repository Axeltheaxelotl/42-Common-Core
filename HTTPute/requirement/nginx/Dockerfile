FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y nginx

COPY default /etc/nginx/sites-available/default
COPY ssl/nginx.crt /etc/nginx/ssl/nginx.crt
COPY ssl/nginx.key /etc/nginx/ssl/nginx.key

CMD ["nginx", "-g", "daemon off;"]