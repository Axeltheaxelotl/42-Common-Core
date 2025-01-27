/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:41:27 by alanty            #+#    #+#             */
/*   Updated: 2025/01/09 17:41:28 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_right(t_recup *recup);
void	ft_left(t_recup *recup);

void	ft_left_right(t_recup *recup)
{
	ft_right(recup);
	ft_left(recup);
}

void	ft_rotate_right_left(t_recup *recup)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = recup->ray.planx;
	olddirx = recup->ray.dirx;
	if (recup->data.rotate_right == 1)
	{
		recup->ray.dirx = recup->ray.dirx * cos(-recup->ray.rotspeed / 2)
			- recup->ray.diry * sin(-recup->ray.rotspeed / 2);
		recup->ray.diry = olddirx * sin(-recup->ray.rotspeed / 2)
			+ recup->ray.diry * cos(-recup->ray.rotspeed / 2);
		recup->ray.planx = recup->ray.planx * cos(-recup->ray.rotspeed / 2)
			- recup->ray.plany * sin(-recup->ray.rotspeed / 2);
		recup->ray.plany = oldplanx * sin(-recup->ray.rotspeed / 2)
			+ recup->ray.plany * cos(-recup->ray.rotspeed / 2);
	}
	ft_rotate_left(recup, olddirx);
}

void	ft_rotate_left(t_recup *recup, double olddirx)
{
	double	oldplanex;

	if (recup->data.rotate_left == 1)
	{
		olddirx = recup->ray.dirx;
		oldplanex = recup->ray.planx;
		recup->ray.dirx = recup->ray.dirx * cos(recup->ray.rotspeed / 2)
			- recup->ray.diry * sin(recup->ray.rotspeed / 2);
		recup->ray.diry = olddirx * sin(recup->ray.rotspeed / 2)
			+ recup->ray.diry * cos(recup->ray.rotspeed / 2);
		recup->ray.planx = recup->ray.planx * cos(recup->ray.rotspeed / 2)
			- recup->ray.plany * sin(recup->ray.rotspeed / 2);
		recup->ray.plany = oldplanex * sin(recup->ray.rotspeed / 2)
			+ recup->ray.plany * cos(recup->ray.rotspeed / 2);
	}
}
