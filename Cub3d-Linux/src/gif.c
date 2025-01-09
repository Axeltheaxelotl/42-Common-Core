/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gif.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:08:53 by smasse            #+#    #+#             */
/*   Updated: 2025/01/09 14:17:24 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*g_tex_paths[81 + 1] = {
	NULL,
	"./textures/gif/1.xpm",
	"./textures/gif/2.xpm",
	"./textures/gif/3.xpm",
	"./textures/gif/4.xpm",
	"./textures/gif/5.xpm",
	"./textures/gif/6.xpm",
	"./textures/gif/7.xpm",
	"./textures/gif/8.xpm",
	"./textures/gif/9.xpm",
	"./textures/gif/10.xpm",
	"./textures/gif/11.xpm",
	"./textures/gif/12.xpm",
	"./textures/gif/13.xpm",
	"./textures/gif/14.xpm",
	"./textures/gif/15.xpm",
	"./textures/gif/16.xpm",
	"./textures/gif/17.xpm",
	"./textures/gif/18.xpm",
	"./textures/gif/19.xpm",
	"./textures/gif/20.xpm",
	"./textures/gif/21.xpm",
	"./textures/gif/22.xpm",
	"./textures/gif/23.xpm",
	"./textures/gif/24.xpm",
	"./textures/gif/25.xpm",
	"./textures/gif/26.xpm",
	"./textures/gif/27.xpm",
	"./textures/gif/28.xpm",
	"./textures/gif/29.xpm",
	"./textures/gif/30.xpm",
	"./textures/gif/31.xpm",
	"./textures/gif/32.xpm",
	"./textures/gif/33.xpm",
	"./textures/gif/34.xpm",
	"./textures/gif/35.xpm",
	"./textures/gif/36.xpm",
	"./textures/gif/37.xpm",
	"./textures/gif/38.xpm",
	"./textures/gif/39.xpm",
	"./textures/gif/40.xpm",
	"./textures/gif/41.xpm",
	"./textures/gif/42.xpm",
	"./textures/gif/43.xpm",
	"./textures/gif/44.xpm",
	"./textures/gif/45.xpm",
	"./textures/gif/46.xpm",
	"./textures/gif/47.xpm",
	"./textures/gif/48.xpm",
	"./textures/gif/49.xpm",
	"./textures/gif/50.xpm",
	"./textures/gif/51.xpm",
	"./textures/gif/52.xpm",
	"./textures/gif/53.xpm",
	"./textures/gif/54.xpm",
	"./textures/gif/55.xpm",
	"./textures/gif/56.xpm",
	"./textures/gif/57.xpm",
	"./textures/gif/58.xpm",
	"./textures/gif/59.xpm",
	"./textures/gif/60.xpm",
	"./textures/gif/61.xpm",
	"./textures/gif/62.xpm",
	"./textures/gif/63.xpm",
	"./textures/gif/64.xpm",
	"./textures/gif/65.xpm",
	"./textures/gif/66.xpm",
	"./textures/gif/67.xpm",
	"./textures/gif/68.xpm",
	"./textures/gif/69.xpm",
	"./textures/gif/70.xpm",
	"./textures/gif/71.xpm",
	"./textures/gif/72.xpm",
	"./textures/gif/73.xpm",
	"./textures/gif/74.xpm",
	"./textures/gif/75.xpm",
	"./textures/gif/76.xpm",
	"./textures/gif/77.xpm",
	"./textures/gif/78.xpm",
	"./textures/gif/79.xpm",
	"./textures/gif/80.xpm",
	"./textures/gif/81.xpm"
};

void	apply_transparency(int *src, int *dst, int pixel_count)
{
	int	i;

	i = 0;
	while (i < pixel_count)
	{
		if ((src[i] & 0x00FFFFFF) == 0)
			dst[i] = src[i] & 0x00FFFFFF;
		else
			dst[i] = src[i] | 0xFF000000;
		i++;
	}
}

static void	*create_transparent_copy(void *mlx, void *img, int width,
		int height)
{
	void		*new_img;
	int			*data;
	int			*new_data;
	t_mlx_info	info;

	new_img = mlx_new_image_alpha(mlx, width, height);
	if (!new_img)
	{
		mlx_destroy_image(mlx, img);
		exit(EXIT_FAILURE);
	}
	data = (int *)mlx_get_data_addr(img, &info.bpp, &info.size_line,
			&info.endian);
	new_data = (int *)mlx_get_data_addr(new_img, &info.bpp, &info.size_line,
			&info.endian);
	apply_transparency(data, new_data, width * height);
	return (new_img);
}

void	*load_xpm(const char *path, void *mlx)
{
	void	*img;
	void	*transparent_img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &width, &height);
	if (!img)
		exit(EXIT_FAILURE);
	transparent_img = create_transparent_copy(mlx, img, width, height);
	mlx_destroy_image(mlx, img);
	return (transparent_img);
}

void	load_textures(t_data *data, void *mlx)
{
	int	i;

	i = 1;
	while (i <= 81)
	{
		data->textures[i] = load_xpm(g_tex_paths[i], mlx);
		i++;
	}
}

void	putgif(t_recup *recup)
{
	static int	i = 1;
	static int	frame_counter = 0;
	static int	direction = 1;

	mlx_put_image_to_window(recup->data.mlx_ptr, recup->data.mlx_win,
		recup->data.textures[i], 0, 0);
	if (frame_counter % 6 == 0)
	{
		i += direction;
		if (i >= 82)
		{
			i = 81;
			direction = -1;
		}
		else if (i <= 1)
		{
			i = 1;
			direction = 1;
		}
	}
	frame_counter++;
}
