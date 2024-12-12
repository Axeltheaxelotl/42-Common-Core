/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:51:26 by alanty            #+#    #+#             */
/*   Updated: 2024/04/05 12:51:28 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

void	transform(t_cam *cam, t_line *line)
{
	scale(line, cam->scale_factor);
	translate(line, cam->move_x, cam->move_y);
}

void	scale(t_line *line, int scale_factor)
{
	line->start.x *= scale_factor;
	line->start.y *= scale_factor;
	line->end.x *= scale_factor;
	line->end.y *= scale_factor;
}

void	translate(t_line *line, int move_x, int move_y)
{
	line->start.x += move_x;
	line->start.y += move_y;
	line->end.x += move_x;
	line->end.y += move_y;
}
