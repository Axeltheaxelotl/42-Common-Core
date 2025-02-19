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
define( 'AUTH_KEY',          'wM:xcN#B7uKmDTHZ F5 1%W-@};t$f kBI9@<Y/1ym-fmxt@QcnMwhL9!)wV9cce' );
define( 'SECURE_AUTH_KEY',   'b]P9_x4H.sDW/>{IeFeMY ^?8aSR%4 ZEw<d$ZBIWxWXfLf%AS=Hb-8.=keQ@j-4' );
define( 'LOGGED_IN_KEY',     'Vl4<2wOY9{-u.; [~l&Fb;]}H~~Bf6#BN~O6muc7GQ`Rfzm~B^J1eAB}ykAQjYq&' );
define( 'NONCE_KEY',         'Np]Iy)Dw+/#roGLC6([P{G72o o *D5;P#w7@e5pX/M[RgSe.OUG?)ZtvR4rA`k(' );
define( 'AUTH_SALT',         'mJFTx1l,RuA.XW:4B]j1-^3s/fNj?s)b1kq/bgu&t`Lz2PVV|S2ffrDeVYSVA hg' );
define( 'SECURE_AUTH_SALT',  '!p@/h44E5g9A&:~}5nF@_ZULwrL|mrQ X$8!p_o*JEFVCOTaR@e}v$Eja&{AzW;-' );
define( 'LOGGED_IN_SALT',    'T<#Dub|m_TGA5}?im9@{{T<Eq$:#KYC=.*!LGIK4NyarZJzSmSetkGOX)3=Di#Qu' );
define( 'NONCE_SALT',        ')p/]_~v<:jD*%[h_G1J^Z[m`etT6V32gqM@vS+*Hpi%ZU?>SLM~5jVV|.36c.@:H' );
define( 'WP_CACHE_KEY_SALT', 'R>i.OnS]ljq8Pu7U&6/lZv8wL!$~,a,eN<UV*n}V&^L{q+R%IrSa=i]xHM?4%TN,' );


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
