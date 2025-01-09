/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:58:31 by smasse            #+#    #+#             */
/*   Updated: 2025/01/09 12:58:32 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void draw_minimap(t_recup *recup)
{
    int mapX, mapY;
    int startX = 10; // Position X de la minimap sur l'écran
    int startY = 10; // Position Y de la minimap sur l'écran
    int minimapWidth = 200; // Largeur de la minimap
    int minimapHeight = 200; // Hauteur de la minimap

    double scaleX = (double)minimapWidth / recup->sizeline;
    double scaleY = (double)minimapHeight / recup->nblines;

    // Dessiner chaque case de la carte sur la minimap
    for (mapY = 0; mapY < recup->nblines; mapY++)
    {
        for (mapX = 0; mapX < recup->sizeline; mapX++)
        {
            int color;

            if (recup->map[mapY][mapX] == '1')
                color = 0xF2FF00; // Couleur pour les murs
            else if (recup->map[mapY][mapX] == '0')
                color = 0x000000; // Couleur pour les espaces vides
            else if (recup->map[mapY][mapX] == '2')
                color = 0xFF0000; // Couleur pour les sprites
            else
                color = 0xFF0000; // Couleur pour les autres éléments

            // Dessiner la case
            int pixelX_start = startX + (int)(mapX * scaleX);
            int pixelY_start = startY + (int)(mapY * scaleY);
            int pixelX_end = startX + (int)((mapX + 1) * scaleX);
            int pixelY_end = startY + (int)((mapY + 1) * scaleY);

            int x, y;
            for (y = pixelY_start; y < pixelY_end; y++)
            {
                for (x = pixelX_start; x < pixelX_end; x++)
                {
                    if (x >= 0 && x < recup->rx && y >= 0 && y < recup->ry)
                        recup->data.addr[y * recup->data.line_length / 4 + x] = color;
                }
            }
        }
    }

    int playerPixelX = startX + (int)(recup->ray.posy * scaleX);
    int playerPixelY = startY + (int)(recup->ray.posx * scaleY);

    int x, y;
    int playerSize = 3;
    for (y = -playerSize; y <= playerSize; y++)
    {
        for (x = -playerSize; x <= playerSize; x++)
        {
            int pixelX = playerPixelX + x;
            int pixelY = playerPixelY + y;
            if (pixelX >= 0 && pixelX < recup->rx && pixelY >= 0 && pixelY < recup->ry)
                recup->data.addr[pixelY * recup->data.line_length / 4 + pixelX] = 0x00FF00;
        }
    }
}