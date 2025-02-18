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
define( 'AUTH_KEY',          '>*40F?qHqxZ.M[6t @4-GZ1khvnKwFM_3y7AZLSBD96se7Q$Q4CKb.,+2?:99,p;' );
define( 'SECURE_AUTH_KEY',   'uQoUAd|ubKr4cx})pNrK14_0;voJ-|^x]{.e5SB^ZZBqyej@F.,,tLKYnEah.mk=' );
define( 'LOGGED_IN_KEY',     'O.*m_4kMU,iJg/;35rkycv&eDGQkv`9e$OPrTQPzFJb?ehZ)&ZJzGb@{#A KLMkj' );
define( 'NONCE_KEY',         '$%*US9.-N^2%}+&`^dIU`xFdPqCCc]%)p4e(Z-(sW.AvB}hiAjV_f92mD9uZ0.5*' );
define( 'AUTH_SALT',         'NuLoGCjJN1TiI..tnr0P{ek|JO0bA(K{1|8Z|u[X~dZn;{xGK+9U)4mHj4.`Uz5#' );
define( 'SECURE_AUTH_SALT',  'I7,#D9BIPu8e!gDs%F99i=j5x]d?xJe-e@;^_&uT4ljU7YI5=U4s3SqS[!{uurm)' );
define( 'LOGGED_IN_SALT',    'LlR!sw/Rw,AeeH-vNv|o(1bro_lYOF lyg*8s}ns</iU4aK_#;gTix{q)EEurKIO' );
define( 'NONCE_SALT',        'v0xnCI7p(zq(wEB0h<:sVy,rIe8`A98tZ%,TgB:-7AKNuL!g+P4 )y>PqfYM|~o1' );
define( 'WP_CACHE_KEY_SALT', '/pH`aN?(DJX/Xz,cYrJVf g`4;$!Doh<)_Pns9|zMTc6 aD7YF7wv??Au.=s~IU{' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/* Add any custom values between this line and the "stop editing" line. */
define('WP_HOME', 'https://alanty.42.fr');
define('WP_SITEURL', 'https://alanty.42.fr');

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