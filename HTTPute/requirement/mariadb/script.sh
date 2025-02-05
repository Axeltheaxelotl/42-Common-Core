#!/bin/bash

mysql_install_db --user=mysql --ldata=/var/lib/mysql
mysqld --init-file=/etc/mysql/init.sql