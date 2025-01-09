/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2025/01/09 17:15:28 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_animate_doors(t_recup *recup);

void	ft_get_texture_adress(t_recup *recup)
{
	recup->texture[0].addr = (int *)mlx_get_data_addr(recup->texture[0].img,
			&recup->texture[0].bits_per_pixel, &recup->texture[0].line_length,
			&recup->texture[0].endian);
	recup->texture[1].addr = (int *)mlx_get_data_addr(recup->texture[1].img,
			&recup->texture[1].bits_per_pixel, &recup->texture[1].line_length,
			&recup->texture[1].endian);
	recup->texture[2].addr = (int *)mlx_get_data_addr(recup->texture[2].img,
			&recup->texture[2].bits_per_pixel, &recup->texture[2].line_length,
			&recup->texture[2].endian);
	recup->texture[3].addr = (int *)mlx_get_data_addr(recup->texture[3].img,
			&recup->texture[3].bits_per_pixel, &recup->texture[3].line_length,
			&recup->texture[3].endian);
	recup->texture[4].addr = (int *)mlx_get_data_addr(recup->texture[4].img,
			&recup->texture[4].bits_per_pixel, &recup->texture[4].line_length,
			&recup->texture[4].endian);
}

void	ft_get_texture(t_recup *recup)
{
	recup->texture[0].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
			recup->no, &(recup->texture[0].width), &(recup->texture[0].height));
	if (!recup->texture[0].img)
		ft_error(recup, "Texture SO\n");
	recup->texture[1].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
			recup->so, &(recup->texture[1].width), &(recup->texture[1].height));
	if (!recup->texture[1].img)
		ft_error(recup, "Texture NO\n");
	recup->texture[2].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
			recup->we, &(recup->texture[2].width), &(recup->texture[2].height));
	if (!recup->texture[2].img)
		ft_error(recup, "Texture EA\n");
	recup->texture[3].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
			recup->ea, &(recup->texture[3].width), &(recup->texture[3].height));
	if (!recup->texture[3].img)
		ft_error(recup, "Texture WE\n");
	recup->texture[4].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
			recup->sp, &(recup->texture[4].width), &(recup->texture[4].height));
	if (!recup->texture[4].img)
		ft_error(recup, "Texture S\n");
	ft_get_texture_adress(recup);
}

void	ft_mousedir(t_recup *recup)
{
	int			x;
	int			y;
	static int	moved = 0;

	mlx_mouse_get_pos(recup->data.mlx_ptr, recup->data.mlx_win, &x, &y);
	if (x < recup->rx * 0.2)
	{
		recup->data.rotate_left = 1;
		recup->data.rotate_right = 0;
		moved = 1;
	}
	else if (x > recup->rx * 0.8)
	{
		recup->data.rotate_right = 1;
		recup->data.rotate_left = 0;
		moved = 1;
	}
	else if (moved == 1)
	{
		moved = 0;
		recup->data.rotate_right = 0;
		recup->data.rotate_left = 0;
	}
}
void	putgif(t_recup *recup);

void	ft_draw_scene(t_recup *recup)
{
	int	i;

	recup->ray.x = 0;
	while (recup->ray.x < recup->rx)
	{
		ft_initialisation3(recup);
		ft_stepsidedist(recup);
		ft_color_column(recup);
		recup->s.zbuffer[recup->ray.x] = recup->ray.perpwalldist;
		recup->ray.x++;
	}
	ft_sprite(recup);
	draw_minimap(recup);
	i = 0;
	while (i < recup->rx * recup->ry)
	{
		recup->data.addr[i] |= 0xFF000000;
		i++;
	}
	mlx_put_image_to_window(recup->data.mlx_ptr, recup->data.mlx_win,
		recup->data.img, 0, 0);
}

int	ft_raycasting(t_recup *recup)
{
	ft_draw_scene(recup);
	putgif(recup);
	ft_forward_back(recup);
	ft_left_right(recup);
	ft_mousedir(recup);
	ft_rotate_right_left(recup);
	ft_animate_doors(recup);
	ft_swap(recup);
	return (0);
}

