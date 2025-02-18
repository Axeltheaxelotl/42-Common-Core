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
define( 'AUTH_KEY',          '(O)Y<{SPPgh1E&#FnjbJ;w#RV^|^PAcD5:ToLcW2+c//*e-B10GSF,@u&5j@C0E$' );
define( 'SECURE_AUTH_KEY',   'A *|Ut91%NjYT#4^ebg$1k7W)Zt1k|O6b`<$%$jPYKBIK{aryc/)`i@e.P1F*TL0' );
define( 'LOGGED_IN_KEY',     'AA6 AA eTU1eY`S!jl5u434.tZW#I6Zg>*:JgN9_i8..uNQju#t^^@z]8I[9Clj4' );
define( 'NONCE_KEY',         '>(]B:bo.Z&zu~6i@Gv}~`GS7~R6?:SfcxN:}9V8EFMT^mT}q-}AgV!-7z.jvieE(' );
define( 'AUTH_SALT',         'BLC2,w-!]5Qgi4yK!l1XSY%BfHJdt|pD[~P@{|vDfg|(k@)]8TgRqT6{/], XmoX' );
define( 'SECURE_AUTH_SALT',  '!5Dbh&m5 Q= v4`Da LV85Hgp=BzKesG^T~_U*F]y]6|b5-;8Khp$^D(VX[YtqQb' );
define( 'LOGGED_IN_SALT',    '`SufpX^m.6WSuY%N%K0d+qlD/WF.htax![[ TU^A1-@L@zlX_; 3ft!c&_ZK,DHw' );
define( 'NONCE_SALT',        'vIimgwleQ8qznwG]R:Gq!^v-]q,eF,%~ovJ}S@hEUGaz*mPX)y|K%+M7=|bHWV}Q' );
define( 'WP_CACHE_KEY_SALT', 'EU!~A=pllbh0};Yh1jt@4x:k1@89Eg/;*@ -s%U[C;-rh#M/]8QajyzrlzGDaY5h' );


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
