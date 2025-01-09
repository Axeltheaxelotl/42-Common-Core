/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2025/01/09 18:09:33 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_initialisation2(t_recup *recup)
{
	recup->s.zbuffer = (double *)malloc(sizeof(double) * recup->rx);
	if (!recup->s.zbuffer)
		exit(0);
	recup->data.forward = 0;
	recup->data.back = 0;
	recup->data.left = 0;
	recup->data.right = 0;
	recup->data.rotate_right = 0;
	recup->data.rotate_left = 0;
	recup->ray.posx = (double)recup->dx + 0.5;
	recup->ray.posy = (double)recup->dy + 0.5;
	recup->ray.dirx = 0;
	recup->ray.diry = 0;
	recup->ray.planx = 0;
	recup->ray.plany = 0;
	ft_init_dir(recup);
}

void	ft_initialisation3(t_recup *recup)
{
	recup->ray.hit = 0;
	recup->ray.perpwalldist = 0;
	recup->ray.camerax = 2 * recup->ray.x / (double)recup->rx - 1;
	recup->ray.raydirx = recup->ray.dirx + recup->ray.planx * \
						recup->ray.camerax;
	recup->ray.raydiry = recup->ray.diry + recup->ray.plany * \
						recup->ray.camerax;
	recup->ray.mapx = (int)recup->ray.posx;
	recup->ray.mapy = (int)recup->ray.posy;
	recup->ray.movespeed = 0.1;
	recup->ray.rotspeed = 0.033 * 1.8;
	ft_init_more3(recup);
}

void	ft_init_texture(t_recup *recup)
{
	if (recup->ray.side == 0 && recup->ray.raydirx < 0)
		recup->t.texdir = 0;
	if (recup->ray.side == 0 && recup->ray.raydirx >= 0)
		recup->t.texdir = 1;
	if (recup->ray.side == 1 && recup->ray.raydiry < 0)
		recup->t.texdir = 2;
	if (recup->ray.side == 1 && recup->ray.raydiry >= 0)
		recup->t.texdir = 3;
	if (recup->ray.side == 0)
		recup->t.wallx = recup->ray.posy + recup->ray.perpwalldist \
						* recup->ray.raydiry;
	else
		recup->t.wallx = recup->ray.posx + recup->ray.perpwalldist \
						* recup->ray.raydirx;
	recup->t.wallx -= floor((recup->t.wallx));
}

void	ft_count_sprites(t_recup *recup)
{
	int	i;
	int	j;

	i = -1;
	recup->s.nbspr = 0;
	while (++i < recup->nblines)
	{
		j = -1;
		while (++j < recup->sizeline)
		{
			if (recup->map[i][j] == '2')
				recup->s.nbspr += 1;
		}
	}
}

void	ft_allocate_sprite_memory(t_recup *recup)
{
	recup->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * recup->s.nbspr);
	if (!recup->sxy)
		ft_error(recup, "Malloc sxy*");
	recup->s.order = (int *)malloc(sizeof(int) * recup->s.nbspr);
	if (!recup->s.order)
		ft_error(recup, "Malloc s.order*");
	recup->s.dist = (double *)malloc(sizeof(double) * recup->s.nbspr);
	if (!recup->s.dist)
		ft_error(recup, "Malloc s.dist*");
}
