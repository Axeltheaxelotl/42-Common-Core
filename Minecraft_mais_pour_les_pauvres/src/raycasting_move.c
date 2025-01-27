/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2025/01/09 17:37:32 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_forward(t_recup *recup)
{
	if (recup->data.forward == 1)
	{
		if (recup->map[(int)(recup->ray.posx + (recup->ray.dirx
					* recup->ray.movespeed * 2))][(int)recup->ray.posy] == '0'
			|| recup->map[(int)(recup->ray.posx + (recup->ray.dirx
					* recup->ray.movespeed * 2))][(int)recup->ray.posy] == 'O'
			|| recup->map[(int)(recup->ray.posx + (recup->ray.dirx
					* recup->ray.movespeed * 2))][(int)recup->ray.posy] == ' ')
			recup->ray.posx += recup->ray.dirx * recup->ray.movespeed;
		if (recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy
				+ (recup->ray.diry * recup->ray.movespeed * 2))] == '0'
			|| recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy
				+ (recup->ray.diry * recup->ray.movespeed * 2))] == 'O'
			|| recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy
				+ (recup->ray.diry * recup->ray.movespeed * 2))] == ' ')
			recup->ray.posy += recup->ray.diry * recup->ray.movespeed;
	}
}

void	ft_back(t_recup *recup)
{
	if (recup->data.back == 1)
	{
		if (recup->map[(int)(recup->ray.posx - (recup->ray.dirx
					* recup->ray.movespeed * 2))][(int)recup->ray.posy] == '0'
			|| recup->map[(int)(recup->ray.posx - (recup->ray.dirx
					* recup->ray.movespeed * 2))][(int)recup->ray.posy] == 'O'
			|| recup->map[(int)(recup->ray.posx - (recup->ray.dirx
					* recup->ray.movespeed * 2))][(int)recup->ray.posy] == ' ')
			recup->ray.posx -= recup->ray.dirx * recup->ray.movespeed;
		if (recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy
				- (recup->ray.diry * recup->ray.movespeed * 2))] == '0'
			|| recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy
				- (recup->ray.diry * recup->ray.movespeed * 2))] == 'O'
			|| recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy
				- (recup->ray.diry * recup->ray.movespeed * 2))] == ' ')
			recup->ray.posy -= recup->ray.diry * recup->ray.movespeed;
	}
}

void	ft_forward_back(t_recup *recup)
{
	ft_forward(recup);
	ft_back(recup);
}

void	ft_right(t_recup *recup)
{
	if (recup->data.right == 1)
	{
		if (recup->map[(int)(recup->ray.posx + recup->ray.diry
				* (recup->ray.movespeed * 2))][(int)recup->ray.posy] == '0'
			|| recup->map[(int)(recup->ray.posx + recup->ray.diry
				* (recup->ray.movespeed * 2))][(int)recup->ray.posy] == 'O'
			|| recup->map[(int)(recup->ray.posx + recup->ray.diry
				* (recup->ray.movespeed * 2))][(int)recup->ray.posy] == ' ')
			recup->ray.posx += recup->ray.diry * recup->ray.movespeed;
		if (recup->map[(int)recup->ray.posx][(int)(recup->ray.posy
			- recup->ray.dirx * (recup->ray.movespeed * 2))] == '0'
			|| recup->map[(int)recup->ray.posx][(int)(recup->ray.posy
				- recup->ray.dirx * (recup->ray.movespeed * 2))] == 'O'
			|| recup->map[(int)recup->ray.posx][(int)(recup->ray.posy
				- recup->ray.dirx * (recup->ray.movespeed * 2))] == ' ')
			recup->ray.posy -= recup->ray.dirx * recup->ray.movespeed;
	}
}

void	ft_left(t_recup *recup)
{
	if (recup->data.left == 1)
	{
		if (recup->map[(int)(recup->ray.posx - recup->ray.diry
				* (recup->ray.movespeed * 2))][(int)recup->ray.posy] == '0'
			|| recup->map[(int)(recup->ray.posx - recup->ray.diry
				* (recup->ray.movespeed * 2))][(int)recup->ray.posy] == 'O'
			|| recup->map[(int)(recup->ray.posx - recup->ray.diry
				* (recup->ray.movespeed * 2))][(int)recup->ray.posy] == ' ')
			recup->ray.posx -= recup->ray.diry * recup->ray.movespeed;
		if (recup->map[(int)recup->ray.posx][(int)(recup->ray.posy
			+ recup->ray.dirx * (recup->ray.movespeed * 2))] == '0'
			|| recup->map[(int)recup->ray.posx][(int)(recup->ray.posy
				+ recup->ray.dirx * (recup->ray.movespeed * 2))] == 'O'
			|| recup->map[(int)recup->ray.posx][(int)(recup->ray.posy
				+ recup->ray.dirx * (recup->ray.movespeed * 2))] == ' ')
			recup->ray.posy += recup->ray.dirx * recup->ray.movespeed;
	}
}
