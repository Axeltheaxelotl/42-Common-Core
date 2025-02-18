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
define( 'AUTH_KEY',          'AX)C=2%5z#D3G~tF0jh>K_yMJ|Y@]Z)G!WnT-[?hC3LM8HJ+3q|W)E~5~l`gk+I@' );
define( 'SECURE_AUTH_KEY',   '0}HfG--+^H@Bm_Hli<L9z[Z@BBKJO?^~NY-_2{FWL>]6uGE$X3)U}hC3(jc.r9Jr' );
define( 'LOGGED_IN_KEY',     'ws]y &Ef])|xWgr^yTx`|@d!/aig^74MG*L6|O8!NgFa;RWn.]U(5MT DM8?io(y' );
define( 'NONCE_KEY',         'IRJkaHju2N9/E^b%O(.zvL(mog(eGPHH4!q1Y~oI[8[X-uFIt#LBHRNRzBQ5G/X4' );
define( 'AUTH_SALT',         'gRWq/Z?~*!OJ.QU+,:^!y|_orf8WrQ4HYq(!wj 0j HFUxj;fLhE9}eY=p$&%a5G' );
define( 'SECURE_AUTH_SALT',  'N+9/Q_(;W;X_V{S1]fDh}4.[iN]C@-jet8PC>Ewr 1G-}uo2Yu.P?)Am=W$i-].g' );
define( 'LOGGED_IN_SALT',    ')-g-Z8s>aWvq2.@&8fz ULHK:^$%i%v}zL#ap.dx<eohB}O53r&!0Fjz%a6R:}Z@' );
define( 'NONCE_SALT',        'wclFEANslTd>_EYry-`;5.^v&I#o[|{lDb|`#_hy7#*@%pMSsgjFy[wz.X!`|6Vg' );
define( 'WP_CACHE_KEY_SALT', 'K/O&$v!ciS~@~@n<Fp7)~-K(){&YSk4p 9$b|]sXP(G/ q<cd:FrD2t%-)g?r jO' );


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
