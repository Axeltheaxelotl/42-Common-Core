/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_boite_a_foutre.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:35:47 by alanty            #+#    #+#             */
/*   Updated: 2025/01/10 10:03:56 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//parsing_colot_resolution_texture
void	ft_color_resolution(char **str, t_recup *recup)
{
    int	i;

    i = 0;
    recup->i = 1;
    recup->rx = RES_X;
    recup->ry = RES_Y;
    if (recup->sizeline > 0 && (!recup->no || !recup->so || !recup->we
        || !recup->ea || !recup->sp))
        recup->erreur = 2;
    if ((recup->no || recup->so || recup->we || recup->ea || recup->sp)
        && (recup->rx == 0 || recup->ry == 0))
        recup->erreur = 2;
    if (*str[i] == 'F')
        recup->f = ft_atoi3(*str, recup);
    else if (*str[i] == 'C')
        recup->c = ft_atoi3(*str, recup);
}


//minimap

void	draw_minimap(t_recup *recup)
{
	t_map_params	map_params;
	t_player_params	player_params;

	map_params.start_x = 10;
	map_params.start_y = 10;
	map_params.scale_x = 200.0 / recup->sizeline;
	map_params.scale_y = 200.0 / recup->nblines;
	player_params.start_x = 10;
	player_params.start_y = 10;
	player_params.scale = 200.0 / recup->sizeline;
	draw_map(recup, &map_params);
	draw_player(recup, &player_params);
}
