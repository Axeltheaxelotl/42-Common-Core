/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2025/01/09 17:28:00 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_read_map(int fd, t_recup *recup)
{
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, recup);
		if (recup->insidemap == 1 && ft_lignevide(str) == 0
			&& recup->count < recup->nblines)
			recup->lignevide = 1;
		recup->insidemap = ft_is_map(str, recup);
		if (recup->insidemap == 1)
		{
			recup->count++;
			ft_copy_map(str, recup);
		}
		free(str);
	}
}

int	ft_parsing_map(char *fichier, t_recup *recup)
{
	int	fd;

	fd = open(fichier, O_RDONLY);
	recup->map = malloc(sizeof(char *) * recup->nblines);
	if (!recup->map)
		return (0);
	ft_read_map(fd, recup);
	close(fd);
	ft_init_sprite(recup);
	return (0);
}

void	ft_parse_file(int fd, t_recup *recup)
{
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, recup);
		if (recup->erreur == 2)
			ft_error(recup, "La partie parsing detecte une erreur\n");
		ft_color_resolution(&str, recup);
		ft_texture(str, recup);
		ft_map(str, recup);
		free(str);
	}
}

void	ft_parsing(char *fichier, t_recup *recup)
{
	int	fd;

	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_error(recup, "Invalide : is a directory\n");
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Fichier .cub invalide\n");
	recup->erreur = 0;
	ft_parse_file(fd, recup);
	close(fd);
	if (recup->sizeline == 0 || recup->nblines == 0)
		ft_error(recup, "Map absente\n");
	ft_parsing_map(fichier, recup);
}

int	ft_cub(char *str, t_recup *recup)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(recup, "Nom de la map invalide\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, recup);
	else
		ft_error(recup, "Nom de la map invalide\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_recup	recup;

	recup.save = 0;
	ft_initialisation(&recup);
	if (argc == 2 || (argc == 3 && ft_check_save(argv[2]) == 1))
	{
		if (argc == 3)
			recup.save = 1;
		ft_cub(argv[1], &recup);
	}
	else
		write(1, "Error\nArguments invalides\n", 30);
}
