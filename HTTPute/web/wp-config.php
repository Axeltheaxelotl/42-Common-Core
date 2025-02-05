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
define( 'DB_NAME', 'WordFumer' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'mot_de_passe' );

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
define( 'AUTH_KEY',          'JSiv%WeuA}e#-OlYeQlM2gExuU;nA=fZP. p+SKY[<G,OUrJ6]x[>sw97j*@ZkBi' );
define( 'SECURE_AUTH_KEY',   '3#h)~~fzgMbj6BU[6XwcjLDfE>5~m[GqCxQvamE(ZI9iJ$=d-=[tp8Yx~x h$L[1' );
define( 'LOGGED_IN_KEY',     'L1D/,uX+}c: x(puS_BO*UA%&)2.Y*-!oHWu_Jxfr``0u}x4[][A!i|?Z/5(9UK}' );
define( 'NONCE_KEY',         ',uICBWF$_K/oy:AUBQpi1nItID{!^6fqUr+D*10b7]~J}81F0S|b|f$ZnZcg`!-l' );
define( 'AUTH_SALT',         'B7F^kfGms$OZ[IFEPWK^9ENZq`o^w`>lT::}`F{H*_ 20+{XtfQ_Zb.{W{m&cD?C' );
define( 'SECURE_AUTH_SALT',  'ypH6l#m px)L%=Q[`lWe?xCw!eeWMv,srsmGC:Xu{oHPc<<u|qIIcs4C*p?Pi,[V' );
define( 'LOGGED_IN_SALT',    '6mehqg3B&yj+wsN#(Dsp9^%=XhD=C7<*H7.p|El&&Y}.}5w(bP-Q|l663;]8jFwj' );
define( 'NONCE_SALT',        '4Y!%=*ZTX6i@5WQ%uR$>U|wUwUe<=ft^k@dkB{PZ`3p}m{8&,nwisU$$i8nej[N_' );
define( 'WP_CACHE_KEY_SALT', '@I*Bho6Jb;&&s&0[S_8`3h}S2$kOC $H#-:(MK69$qAT4UB>{wVM}SRy%(Q*O.S,' );


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
