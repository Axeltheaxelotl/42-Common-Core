#include "../inc/cub3d.h"

static void draw_square(t_recup *recup, int start_x, int start_y, int end_x,
	int end_y, int color)
{
	int	x;
	int	y;

	for (y = start_y; y < end_y; y++)
	{
		for (x = start_x; x < end_x; x++)
		{
			if (x >= 0 && x < recup->rx && y >= 0 && y < recup->ry)
				recup->data.addr[y * recup->data.line_length / 4 + x] = color;
        }
	}
}

static void draw_player(t_recup *recup, int start_x, int start_y, double scale)
{
	int	player_pixel_x;
	int	player_pixel_y;
	int	player_size;
	int	pixel_x;
	int	pixel_y;
	int	x;
	int	y;

	player_pixel_x = start_x + (int)(recup->ray.posy * scale);
	player_pixel_y = start_y + (int)(recup->ray.posx * scale);
	player_size = 3;
	for (y = -player_size; y <= player_size; y++)
	{
		for (x = -player_size; x <= player_size; x++)
		{
			pixel_x = player_pixel_x + x;
			pixel_y = player_pixel_y + y;
			if (pixel_x >= 0 && pixel_x < recup->rx && pixel_y >= 0
				&& pixel_y < recup->ry)
				recup->data.addr[pixel_y * recup->data.line_length / 4
					+ pixel_x] = 0x00FF00;
		}
	}
}

static void draw_map(t_recup *recup, int start_x, int start_y, double scale_x,
	double scale_y)
{
	int	map_x;
	int	map_y;
	int	color;
	int	pixel_x_start;
	int	pixel_y_start;
	int	pixel_x_end;
	int	pixel_y_end;

	for (map_y = 0; map_y < recup->nblines; map_y++)
	{
		for (map_x = 0; map_x < recup->sizeline; map_x++)
		{
			if (recup->map[map_y][map_x] == '1')
				color = 0xF2FF00;
			else if (recup->map[map_y][map_x] == '0')
				color = 0x000000;
			else
				color = 0xFF0000;
			pixel_x_start = start_x + (int)(map_x * scale_x);
			pixel_y_start = start_y + (int)(map_y * scale_y);
			pixel_x_end = start_x + (int)((map_x + 1) * scale_x);
			pixel_y_end = start_y + (int)((map_y + 1) * scale_y);
			draw_square(recup, pixel_x_start, pixel_y_start, pixel_x_end,
				pixel_y_end, color);
		}
	}
}

void draw_minimap(t_recup *recup)
{
	int start_x;
	int start_y;
	int minimap_width;
	int minimap_height;
	double scale_x;
	double scale_y;

	start_x = 10;
	start_y = 10;
	minimap_width = 200;
	minimap_height = 200;
	scale_x = (double)minimap_width / recup->sizeline;
	scale_y = (double)minimap_height / recup->nblines;
	draw_map(recup, start_x, start_y, scale_x, scale_y);
	draw_player(recup, start_x, start_y, scale_x);
}