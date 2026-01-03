/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:37:49 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 14:38:37 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	char	*trimmed;

	if (!line || is_line_empty(line))
		return (0);
	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	if (*trimmed == '0' || *trimmed == '1' || *trimmed == ' ')
		return (1);
	return (0);
}

static int	check_coma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (0);
		i++;
	}
	return (1);
}

static int	pars_rgb_value(t_gc *gc, char *rgb_val)
{
	int	i;
	int	value;

	i = 0;
	rgb_val = ft_strtrim(gc, rgb_val, "\n\t");
	while (rgb_val[i])
	{
		if (rgb_val[i] < '0' || rgb_val[i] > '9')
			return (-1);
		i++;
	}
	value = ft_atoi(rgb_val);
	if (value < 0 || value > 255)
	{
		printf("ERROR\nTHe value of color must be between 0 and 255\n");
		return (-1);
	}
	return (value);
}

int	pars_colors(t_gc *gc, char *line, t_color *color)
{
	char	**rgb_path;
	int		i;

	line = ft_strtrim(gc, line, "\t\n");
	if (!line)
		return (0);
	if (!check_coma(line))
		return (printf("ERROR\nThe structure of color %s is invalid\n", line),
			0);
	rgb_path = ft_split(gc, line, ',');
	if (!rgb_path)
		return (0);
	i = 0;
	while (rgb_path[i])
		i++;
	if (i != 3)
		return (printf("ERROR\nThe color must have 3 values R,G,B\n"), 0);
	color->r = pars_rgb_value(gc, rgb_path[0]);
	color->g = pars_rgb_value(gc, rgb_path[1]);
	color->b = pars_rgb_value(gc, rgb_path[2]);
	if (color->r == -1 || color->g == -1 || color->b == -1)
		return (0);
	return (1);
}
