/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:12 by alanty            #+#    #+#             */
/*   Updated: 2025/01/09 18:35:01 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_square(t_recup *recup, t_draw_params *params)
{
	int	x;
	int	y;

	y = params->start_y;
	while (y < params->end_y)
	{
		x = params->start_x;
		while (x < params->end_x)
		{
			if (x >= 0 && x < recup->rx && y >= 0 && y < recup->ry)
				recup->data.addr[y * recup->data.line_length / 4
					+ x] = params->color;
			x++;
		}
		y++;
	}
}

void	draw_player(t_recup *recup, t_player_params *params)
{
	t_player_draw_params	draw_params;

	draw_params.player_pixel_x = params->start_x
		+ (int)(recup->ray.posy * params->scale);
	draw_params.player_pixel_y = params->start_y
		+ (int)(recup->ray.posx * params->scale);
	draw_params.player_size = 3;
	draw_params.y = -draw_params.player_size;
	while (draw_params.y <= draw_params.player_size)
	{
		draw_params.x = -draw_params.player_size;
		while (draw_params.x <= draw_params.player_size)
		{
			draw_params.pixel_x = draw_params.player_pixel_x + draw_params.x;
			draw_params.pixel_y = draw_params.player_pixel_y + draw_params.y;
			if (draw_params.pixel_x >= 0 && draw_params.pixel_x
				< recup->rx && draw_params.pixel_y >= 0
				&& draw_params.pixel_y < recup->ry)
				recup->data.addr[draw_params.pixel_y
					* recup->data.line_length / 4
					+ draw_params.pixel_x] = 0x00FF00;
			draw_params.x++;
		}
		draw_params.y++;
	}
}

void	set_draw_params(t_map_draw_params *map_draw_params
		, t_map_params *params)
{
	map_draw_params->draw_params.start_x = params->start_x
		+ (int)(map_draw_params->map_x * params->scale_x);
	map_draw_params->draw_params.start_y = params->start_y
		+ (int)(map_draw_params->map_y * params->scale_y);
	map_draw_params->draw_params.end_x = params->start_x
		+ (int)((map_draw_params->map_x + 1) * params->scale_x);
	map_draw_params->draw_params.end_y = params->start_y
		+ (int)((map_draw_params->map_y + 1) * params->scale_y);
}

static void	set_color(t_map_draw_params *map_draw_params, t_recup *recup)
{
	if (recup->map[map_draw_params->map_y][map_draw_params->map_x] == '1')
		map_draw_params->color = 0xF2FF00;
	else if (recup->map[map_draw_params->map_y][map_draw_params->map_x] == '0')
		map_draw_params->color = 0x000000;
	else
		map_draw_params->color = 0xFF0000;
	map_draw_params->draw_params.color = map_draw_params->color;
}

void	draw_map(t_recup *recup, t_map_params *params)
{
	t_map_draw_params	map_draw_params;

	map_draw_params.map_y = 0;
	while (map_draw_params.map_y < recup->nblines)
	{
		map_draw_params.map_x = 0;
		while (map_draw_params.map_x < recup->sizeline)
		{
			set_color(&map_draw_params, recup);
			set_draw_params(&map_draw_params, params);
			draw_square(recup, &map_draw_params.draw_params);
			map_draw_params.map_x++;
		}
		map_draw_params.map_y++;
	}
}
