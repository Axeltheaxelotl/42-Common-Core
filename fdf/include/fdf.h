/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:01:39 by alanty            #+#    #+#             */
/*   Updated: 2024/04/21 16:01:42 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//inclusion des bibliotheques standard
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//Inclusion des bibliotheques graphique et mathematique
# include <math.h>
# include "../mlx_linux/mlx.h"

//Bibliotheque libft
# include "../libft/libft.h"

//Bibliotheque personaliser
# include "keys.h"
# include "colors.h"

//Definition des structures principales

//Structure repesentant un point dans un espace 3D
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color; //Couleur du point
}	t_point;

//Structure representant la carte (ensemble de points)
typedef struct s_map
{
	t_point	**coordinates; //Tableau 2D de point
	int		max_x; //Nombre maximum de point sur l'axe x
	int		max_y; //Nombre maximum de point sur l'axe y
	int		max_z; //Valeur maximal de z dans la carte
	int		min_z; //Valeur minimal de z dans la carte
}	t_map;

//Structure representant une ligne entre deux points
typedef struct s_line
{
	t_point	start; //Point de depart de la ligne
	t_point	end; //Point d'arrivee de la ligne
	float	transform_z; //Facteur de transformation z
}	t_line;

//Structure representant une couleur (pour interpolation)
typedef struct s_color
{
	int	start_color; //Couleur de depart
	int	start_r; //Composante rouge de la couleur de depart
	int	start_g; //Composante verte de la couleur de depart
	int	start_b; //Composante bleu de la couleur de depart 
	int	end_color; //Couleur d'arrivee
	int	end_r; //Composante rouge de la couleur d'arrivee
	int	end_g; //Composante vert de la couleur d'arrivee
	int	end_b; //Composante bleu de la couleur d'arrivee
	int	delta_r; //Difference entre les couleurs rouges
	int	delta_g; //Difference entre les couleurs verts
	int	delta_b; //Difference entre les couleurs bleues
}	t_color;

//Structure representant une image
typedef struct s_image
{
	void	*image; //Image MLX
	int		pixel_bits; //Nombre de bits par pixel
	int		line_bytes; //Nombre d'octets par ligne
	int		endian; //Indicateur de boutisme
	char	*buffer; //Tampon de l'image
	t_line	*line; //Ligne a dessiner
}	t_image;

//Structure representant la camera
typedef struct s_cam
{
	int		projection; //Type de projection
	int		color_pallet; //Palette de couleurs
	float	scale_factor; //Facteur d'echelle
	float	scale_z; //Echelle z
	float	move_x; //Deplacement en x
	float	move_y; //Deplacement en y
	double	alpha; //Angle alpha
	double	beta; //Angle bete
	double	gamma; //Angle gamma
}	t_cam;

//Structure principale representant l'application FDF
typedef struct s_fdf
{
	t_map	*map; //Carte a afficher
	void	*mlx; //Structure MLX
	int		win_x; //Largeur de la fenetre
	int		win_y; //Hauteur de la fenetre
	void	*win; //Fenetre MLX
	t_image	*image; //Image a afficher
	t_cam	*cam; //Camera pour la visualisation
}	t_fdf;

//Definition de constantes utiles pour la fenetre
# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		1200
# define WINDOW_HEIGHT		900
# define MAX_PIXEL			1080000

//Definition des couleurs par default
# define LINE_DEFAULT		C_WHITE
# define BACKGROUND_DEFAULT	C_GREY
# define C_TEXT				C_WHITE

//Autre constantes utiles
# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

//Definition des enumerations pour la projection et le bouteen
enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum e_bool
{
	FALSE,
	TRUE
};

//Prototypes des fonctions

t_map	*read_map(char *file_name);

void	error(int exit_code);

t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_image	*init_image(void *mlx);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_map *map);

t_point	**init_coordinates(int width, int depth);
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);
void	reset(t_fdf *fdf);
void	close_all(t_fdf *fdf, int exit_code);
void	close_map(t_fdf *fdf, int exit_code);
t_color	*color_init(t_point start, t_point end);
t_color	*color_pallet_init(int min_color, int max_color);

float	absolute(float nbr);
float	max(float a, float b);
float	min(float a, float b);

//Fonctions de rendu et de dessin
void	render(t_fdf *fdf);
void	draw_image(t_image *image, int max_x, int max_y);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixel_to_image(t_image *image, float x, float y, int color);
void	clear_image(t_image *image, int image_size);
void	print_menu(t_fdf *fdf);
int		get_color(t_color *color, int i_line, int line_size);

void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);
void	project(t_cam *cam, t_line *line);
void	transform(t_cam *cam, t_line *line);
void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

int		key_handle(int keycode, t_fdf *fdf);

#endif
