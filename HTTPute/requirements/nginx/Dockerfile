FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx

COPY default /etc/nginx/sites-available/

CMD ["nginx", "-g", "daemon off;"]