#!/bin/bash

if [ ! -d "/run/mysqld" ]; then
    mkdir -p /run/mysqld
    chown mysql:mysql /run/mysqld
    chmod 750 /run/mysqld
fi

if [ ! -d "/var/lib/mysql/mysql" ]; then
    chown -R mysql:mysql /var/lib/mysql
    mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null
    tfile=`mktemp`
    if [ ! -f "$tfile" ]; then
        return 1
    fi
	cat << EOF > $tfile

	USE mysql;
    FLUSH PRIVILEGES;
    DELETE FROM mysql.user WHERE User='';
    DROP DATABASE test;
    DELETE FROM mysql.db WHERE Db='test';
    DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
    ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSW';
    CREATE DATABASE wordpress CHARACTER SET utf8 COLLATE utf8_general_ci;
    CREATE USER '$SQL_USR'@'%' IDENTIFIED by '$SQL_PASSW';
    GRANT ALL PRIVILEGES ON wordpress.* TO '$SQL_USR'@'%';
    GRANT ALL PRIVILEGES ON *.* TO '$SQL_USR'@'mariadb' IDENTIFIED BY '$SQL_PASSW';
	FLUSH PRIVILEGES;
EOF

    /usr/bin/mysqld --user=mysql --bootstrap < $tfile
	rm -f $tfile
fi
sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

exec /usr/bin/mysqld --user=mysql