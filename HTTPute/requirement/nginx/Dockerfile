FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y nginx

COPY default /etc/nginx/sites-available

CMD ["nginx", "-g", "daemon off;"]

