/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:50:38 by alanty            #+#    #+#             */
/*   Updated: 2024/04/05 12:50:41 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*get_projection_name(t_fdf *fdf);

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_TEXT, projection);
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "'ECHAP' pour fermer");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Zoom : '-' ou '+'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Déplacement : direction");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotation X : 'S' ou 'W'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotation Y : 'Q' ou 'E'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotation Z : 'A' ou 'D'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "l'échelle: 'Z' ou 'X'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "(Z limitée à 100%)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "la vue de projection :");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Isométrique : 'I'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Perspective : 'P'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Vue de dessus : 'O'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Couleurs : 'ESPACE'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Réinitialiser la vue : 'R'");
}

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Projection isométrique";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Projection perspective";
	else if (fdf->cam->projection == TOP)
		projection = "Vue de dessus";
	return (projection);
}
