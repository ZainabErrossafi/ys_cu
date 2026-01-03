/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:38:53 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 14:39:02 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_xpm_ext(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("ERROR\nThe extension for textures must be .xpm\n");
		return (0);
	}
	return (1);
}

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
	{
		printf("ERROR\nThe extension must be .cub\n");
		return (0);
	}
	return (1);
}

int	check_textures(t_gc *gc, char *line, char **texture)
{
	int		fd;
	char	*path;

	path = ft_strtrim(gc, line, "\t\n ");
	if (!path || ft_strlen(path) == 0)
	{
		printf("ERROR\nThe path is empty\n");
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR\nCan not open the file\n");
		return (0);
	}
	close(fd);
	if (!check_xpm_ext(path))
		return (0);
	*texture = path;
	return (1);
}

int	pars_c(char *line, t_data *data)
{
	if (data->c_flag)
	{
		printf("ERROR\nC duplicated\n");
		return (0);
	}
	data->c_flag = 1;
	return (pars_colors(data->gc, ft_strtrim(data->gc, line + 2, " \t"),
			&data->ceilling));
}

int	pars_f(char *line, t_data *data)
{
	if (data->f_flag)
	{
		printf("ERROR\nF duplicated\n");
		return (0);
	}
	data->f_flag = 1;
	return (pars_colors(data->gc, ft_strtrim(data->gc, line + 2, " \t"),
			&data->floor));
}
