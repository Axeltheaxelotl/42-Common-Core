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
define( 'AUTH_KEY',          '?j=jWp>#B1?7of_>G<L3-~9MI78BF0n$7o/-$`:=~wx)zJCI[Hro%&^,rYFmnv,(' );
define( 'SECURE_AUTH_KEY',   'M5VsIjm-jfgW0X|*$+<tAz .)^~0pMlv!.}!*d~^]ZBA!%`pY)D5o@jv|-,j`d!}' );
define( 'LOGGED_IN_KEY',     'N?*4_mQUr>0cy4#wn&Qo>UTg1/ mM$kR{{`J,aLa7eZt|e50;T;)4+x?PE~zrPB,' );
define( 'NONCE_KEY',         'Pa2}Vs*i8W,a6*~*<|i=sE9CXmC2aK@y(>{15AwnSlvzg`L@Ix[IOl|&S1E|z:ui' );
define( 'AUTH_SALT',         'CtOuHw7KcdM/?`$mdl6hf,lRKy_h-=Yr^geU=Jila`r!+!p*~vp1DJNyex)N_~YD' );
define( 'SECURE_AUTH_SALT',  '~XM1VSL5jPKVPnIn#=}>PgGPgf@~S 8-jf8;Zk+(fih9!k}#^}uWJfk4>Fwa}*ST' );
define( 'LOGGED_IN_SALT',    'Dvg!jEavP@(GhFE^9Pva~zoYk}E|xvR}Cb5xREb(MWNB@{x20!q8 %w:~nqb&0GY' );
define( 'NONCE_SALT',        '[U0na^cRr pB`9Y+TMp6ssRU=$;f*)QCIM<Ss]LdH84:-,I&IYG<itb*K+xqAI|!' );
define( 'WP_CACHE_KEY_SALT', '.klQ+s-+R0kV0%lZw$D5HJoV3I%#`(@0H_p5;W1#B8!*[hKbe=;i0ALQ.{F|MWqa' );


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
