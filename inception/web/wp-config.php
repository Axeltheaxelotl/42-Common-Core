<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          '7lDzkkM&/<0^X8u0qf52liemV6W26L.1~M52@|Q+ZPpg}zC}|DdTBqgK+>6fNjCz' );
define( 'SECURE_AUTH_KEY',   '{0:<otX^8r b%crjww{Rs!uH-[gNRZST6}&k%A<N+55o1!wla)n3xG6zl N~7]lF' );
define( 'LOGGED_IN_KEY',     '<Af%=5S<g%Frb1Qe{/B$xm}IR[Vk5+D.fgsG0pT:m*3MLN5,8g]WHDxy};4}cV!u' );
define( 'NONCE_KEY',         'sgh~}GLt9qG`I*k)r.CS9re<];hVb31q*XWz[i[B;IOa/Q.sMkPn$Tz=}(Y OyVf' );
define( 'AUTH_SALT',         'M<$*v<5Ta_UW:x6g$ %n k@&XVNrKgG^,:5rqq-7Il0jRI;mqTZ*4zLj0m-^6}dt' );
define( 'SECURE_AUTH_SALT',  '-$R=o0`LOPU?-aP[dUD1X]l3H2jK^A&j]HL=l/>8.z_aCJd6wulhO6YzFi+=:T2w' );
define( 'LOGGED_IN_SALT',    '~o*L]a=R?#h@5Lv&H7ohnrndh-=p:4$Q1Q^~JK K>FNBA&Vc~7.rd~?~-;AoXO5&' );
define( 'NONCE_SALT',        '<vRaL|zV3|A[Cv+K(c3&r5q?% F,Fu*<^-QIuF}2IIYa6-7e|e|^g3JXW|M.7&?^' );
define( 'WP_CACHE_KEY_SALT', 'ffWwn0hnFM*#nT0,j++ jadOYX9iH$`lw6slCn3m}E@em<:;1)3!aUM]f)rY:dP!' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
