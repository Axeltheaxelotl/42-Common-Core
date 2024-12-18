FROM debian:latest

RUN apt update && apt upgrade -y && apt install -y nginx

# Copy the default configuration file into the container
COPY default /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]
