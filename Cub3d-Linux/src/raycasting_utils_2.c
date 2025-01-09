/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:26:07 by alanty            #+#    #+#             */
/*   Updated: 2025/01/09 17:26:10 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_get_texture(t_recup *recup);

void	ft_update_door_state(t_recup *recup, int i, int j, double distance)
{
	if (distance < 1.5 && recup->map[i][j] == 'P')
		recup->map[i][j] = 'O';
	else if (distance >= 1.5 && recup->map[i][j] == 'O')
		recup->map[i][j] = 'P';
}

void	ft_animate_doors(t_recup *recup)
{
	double	distance;
	int		i;
	int		j;

	i = 0;
	while (i < recup->nblines)
	{
		j = 0;
		while (j < recup->sizeline)
		{
			if (recup->map[i][j] == 'P' || recup->map[i][j] == 'O')
			{
				distance = sqrt(pow(recup->ray.posx - i, 2)
						+ pow(recup->ray.posy - j, 2));
				ft_update_door_state(recup, i, j, distance);
			}
			j++;
		}
		i++;
	}
}
void	load_textures(t_data *data, void *mlx);

void	ft_mlx_init(t_recup *recup)
{
	recup->data.mlx_ptr = mlx_init();
	if (!recup->data.mlx_ptr)
		ft_error(recup, "Mlx init impossible\n");
	mlx_get_screen_size(recup->data.mlx_ptr, &recup->screenx, &recup->screeny);
	if (recup->rx > recup->screenx)
		recup->rx = recup->screenx;
	if (recup->ry > recup->screeny)
		recup->ry = recup->screeny;
}

void	ft_mlx_create_images(t_recup *recup)
{
	recup->data.img = mlx_new_image(recup->data.mlx_ptr, recup->rx, recup->ry);
	recup->data.addr = (int *)mlx_get_data_addr(recup->data.img,
			&recup->data.bits_per_pixel, &recup->data.line_length,
			&recup->data.endian);
	recup->data.img2 = mlx_new_image(recup->data.mlx_ptr, recup->rx, recup->ry);
	recup->data.addr2 = (int *)mlx_get_data_addr(recup->data.img2,
			&recup->data.bits_per_pixel, &recup->data.line_length,
			&recup->data.endian);
}

int	ft_mlx(t_recup *recup)
{
	ft_initialisation2(recup);
	ft_mlx_init(recup);
	ft_get_texture(recup);
	ft_mlx_create_images(recup);
	if (recup->save == 1)
		ft_raycasting(recup);
	recup->data.mlx_win = mlx_new_window(recup->data.mlx_ptr, recup->rx,
			recup->ry, "Hello world!");
	load_textures(&recup->data, recup->data.mlx_ptr);
	mlx_hook(recup->data.mlx_win, 33, 1L << 17, ft_exit, recup);
	mlx_hook(recup->data.mlx_win, 2, 1L << 0, ft_key_press, recup);
	mlx_loop_hook(recup->data.mlx_ptr, ft_raycasting, recup);
	mlx_hook(recup->data.mlx_win, 3, 1L << 1, ft_key_release, recup);
	mlx_loop(recup->data.mlx_ptr);
	return (0);
}
