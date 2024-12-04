/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gif.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:08:53 by smasse            #+#    #+#             */
/*   Updated: 2024/12/03 19:41:19 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	*load_xpm(char *path, void *mlx)
{
	void	*img;
	void	*new_img;
	int		*data;
	int		*new_data;
	int		width, height;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img)
	{
		exit(1);
	}
	new_img = mlx_new_image_alpha(mlx, width, height);
	if (!new_img)
	{
		mlx_destroy_image(mlx, img);
		exit(1);
	}
	int size_line, bpp, endian;
	data = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
	new_data = (int *)mlx_get_data_addr(new_img, &bpp, &size_line, &endian);
	for (int i = 0; i < width * height; i++)
	{
		if ((data[i] & 0x00FFFFFF) == 0)
			new_data[i] = data[i] & 0x00FFFFFF; // Set alpha to 0 (fully transparent)
		else
			new_data[i] = data[i] | 0xFF000000; // Set alpha to 255 (fully opaque)
	}
	mlx_destroy_image(mlx, img);
	return (new_img);
}

void	load_textures(t_data *data, void *mlx)
{
	data->textures[1] = load_xpm("./textures/gif/1.xpm", mlx);
	data->textures[2] = load_xpm("./textures/gif/2.xpm", mlx);
	data->textures[3] = load_xpm("./textures/gif/3.xpm", mlx);
	data->textures[4] = load_xpm("./textures/gif/4.xpm", mlx);
	data->textures[5] = load_xpm("./textures/gif/5.xpm", mlx);
	data->textures[6] = load_xpm("./textures/gif/6.xpm", mlx);
	data->textures[7] = load_xpm("./textures/gif/7.xpm", mlx);
	data->textures[8] = load_xpm("./textures/gif/8.xpm", mlx);
	data->textures[9] = load_xpm("./textures/gif/9.xpm", mlx);
	data->textures[10] = load_xpm("./textures/gif/10.xpm", mlx);
	data->textures[11] = load_xpm("./textures/gif/11.xpm", mlx);
	data->textures[12] = load_xpm("./textures/gif/12.xpm", mlx);
	data->textures[13] = load_xpm("./textures/gif/13.xpm", mlx);
	data->textures[14] = load_xpm("./textures/gif/14.xpm", mlx);
	data->textures[15] = load_xpm("./textures/gif/15.xpm", mlx);
	data->textures[16] = load_xpm("./textures/gif/16.xpm", mlx);
	data->textures[17] = load_xpm("./textures/gif/17.xpm", mlx);
	data->textures[18] = load_xpm("./textures/gif/18.xpm", mlx);
	data->textures[19] = load_xpm("./textures/gif/19.xpm", mlx);
	data->textures[20] = load_xpm("./textures/gif/20.xpm", mlx);
	data->textures[21] = load_xpm("./textures/gif/21.xpm", mlx);
	data->textures[22] = load_xpm("./textures/gif/22.xpm", mlx);
	data->textures[23] = load_xpm("./textures/gif/23.xpm", mlx);
	data->textures[24] = load_xpm("./textures/gif/24.xpm", mlx);
	data->textures[25] = load_xpm("./textures/gif/25.xpm", mlx);
	data->textures[26] = load_xpm("./textures/gif/26.xpm", mlx);
	data->textures[27] = load_xpm("./textures/gif/27.xpm", mlx);
	data->textures[28] = load_xpm("./textures/gif/28.xpm", mlx);
	data->textures[29] = load_xpm("./textures/gif/29.xpm", mlx);
	data->textures[30] = load_xpm("./textures/gif/30.xpm", mlx);
	data->textures[31] = load_xpm("./textures/gif/31.xpm", mlx);
	data->textures[32] = load_xpm("./textures/gif/32.xpm", mlx);
	data->textures[33] = load_xpm("./textures/gif/33.xpm", mlx);
	data->textures[34] = load_xpm("./textures/gif/34.xpm", mlx);
	data->textures[35] = load_xpm("./textures/gif/35.xpm", mlx);
	data->textures[36] = load_xpm("./textures/gif/36.xpm", mlx);
	data->textures[37] = load_xpm("./textures/gif/37.xpm", mlx);
	data->textures[38] = load_xpm("./textures/gif/38.xpm", mlx);
	data->textures[39] = load_xpm("./textures/gif/39.xpm", mlx);
	data->textures[40] = load_xpm("./textures/gif/40.xpm", mlx);
	data->textures[41] = load_xpm("./textures/gif/41.xpm", mlx);
	data->textures[42] = load_xpm("./textures/gif/42.xpm", mlx);
	data->textures[43] = load_xpm("./textures/gif/43.xpm", mlx);
	data->textures[44] = load_xpm("./textures/gif/44.xpm", mlx);
	data->textures[45] = load_xpm("./textures/gif/45.xpm", mlx);
	data->textures[46] = load_xpm("./textures/gif/46.xpm", mlx);
	data->textures[47] = load_xpm("./textures/gif/47.xpm", mlx);
	data->textures[48] = load_xpm("./textures/gif/48.xpm", mlx);
	data->textures[49] = load_xpm("./textures/gif/49.xpm", mlx);
	data->textures[50] = load_xpm("./textures/gif/50.xpm", mlx);
	data->textures[51] = load_xpm("./textures/gif/51.xpm", mlx);
	data->textures[52] = load_xpm("./textures/gif/52.xpm", mlx);
	data->textures[53] = load_xpm("./textures/gif/53.xpm", mlx);
	data->textures[54] = load_xpm("./textures/gif/54.xpm", mlx);
	data->textures[55] = load_xpm("./textures/gif/55.xpm", mlx);
	data->textures[56] = load_xpm("./textures/gif/56.xpm", mlx);
	data->textures[57] = load_xpm("./textures/gif/57.xpm", mlx);
	data->textures[58] = load_xpm("./textures/gif/58.xpm", mlx);
	data->textures[59] = load_xpm("./textures/gif/59.xpm", mlx);
	data->textures[60] = load_xpm("./textures/gif/60.xpm", mlx);
	data->textures[61] = load_xpm("./textures/gif/61.xpm", mlx);
	data->textures[62] = load_xpm("./textures/gif/62.xpm", mlx);
	data->textures[63] = load_xpm("./textures/gif/63.xpm", mlx);
	data->textures[64] = load_xpm("./textures/gif/64.xpm", mlx);
	data->textures[65] = load_xpm("./textures/gif/65.xpm", mlx);
	data->textures[66] = load_xpm("./textures/gif/66.xpm", mlx);
	data->textures[67] = load_xpm("./textures/gif/67.xpm", mlx);
	data->textures[68] = load_xpm("./textures/gif/68.xpm", mlx);
	data->textures[69] = load_xpm("./textures/gif/69.xpm", mlx);
	data->textures[70] = load_xpm("./textures/gif/70.xpm", mlx);
	data->textures[71] = load_xpm("./textures/gif/71.xpm", mlx);
	data->textures[72] = load_xpm("./textures/gif/72.xpm", mlx);
	data->textures[73] = load_xpm("./textures/gif/73.xpm", mlx);
	data->textures[74] = load_xpm("./textures/gif/74.xpm", mlx);
	data->textures[75] = load_xpm("./textures/gif/75.xpm", mlx);
	data->textures[76] = load_xpm("./textures/gif/76.xpm", mlx);
	data->textures[77] = load_xpm("./textures/gif/77.xpm", mlx);
	data->textures[78] = load_xpm("./textures/gif/78.xpm", mlx);
	data->textures[79] = load_xpm("./textures/gif/79.xpm", mlx);
	data->textures[80] = load_xpm("./textures/gif/80.xpm", mlx);
	data->textures[81] = load_xpm("./textures/gif/81.xpm", mlx);
}

void	putgif(t_recup *recup)
{
	static int i = 1;
	static int frame_counter = 0;
	static int direction = 1; // 1 for up, -1 for down

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