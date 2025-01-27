/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:13:06 by alanty            #+#    #+#             */
/*   Updated: 2025/01/09 18:13:07 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_allocate_sprite_memory(t_recup *recup);
void	ft_count_sprites(t_recup *recup);

void	ft_init_sprite(t_recup *recup)
{
	ft_verify_errors(recup);
	ft_count_sprites(recup);
	ft_allocate_sprite_memory(recup);
	ft_init_sprite2(recup, 0, 0, 0);
	ft_mlx(recup);
}

void	ft_init_sprite2(t_recup *recup, int i, int j, int v)
{
	i = i - 1;
	while (++i < recup->nblines)
	{
		j = -1;
		while (++j < recup->sizeline)
		{
			if (recup->map[i][j] == '2')
			{
				recup->sxy[v].x = (double)i + 0.5;
				recup->sxy[v].y = (double)j + 0.5;
				v++;
			}
		}
	}
}
