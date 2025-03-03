# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <alanty@student.42luxembourg.lu     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 14:31:15 by alanty            #+#    #+#              #
#    Updated: 2025/03/03 14:31:16 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./srcs/.env
export

all:
	sudo grep -q "127.0.0.1 alanty.42.fr" /etc/hosts || sudo echo "127.0.0.1 alanty.42.fr" >> /etc/hosts
	sudo grep -q "127.0.0.1 www.alanty.42.fr" /etc/hosts || sudo echo "127.0.0.1 www.alanty.42.fr" >> /etc/hosts
	mkdir -p ~/data
	chmod 777 -R ~/data
	cd srcs && docker compose build && docker compose up -d

clean:
	cd srcs && docker compose down

fclean:
	make clean
	docker system prune --all
	sudo rm -rf /home/alanty/data
	sudo sed -i '/127\.0\.0\.1 alanty\.42\.fr/d' /etc/hosts
	sudo sed -i '/127\.0\.0\.1 www\.alanty\.42\.fr/d' /etc/hosts
re:
	make fclean
	make all

