/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:35:48 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 14:35:50 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static int	is_config_line(char *trimmed)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(trimmed, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(trimmed, "C ", 2) == 0)
		return (1);
	return (0);
}

static int	skip_empty_lines(char **lines, int i, int total_lines)
{
	while (i < total_lines && (ft_strlen(lines[i]) == 0
			|| is_line_empty(lines[i])))
		i++;
	return (i);
}

static int	find_map_start(char **lines, int i, int total_lines, int *found_map)
{
	i = skip_empty_lines(lines, i, total_lines);
	if (i < total_lines && is_map_line(lines[i]))
	{
		*found_map = 1;
		return (i);
	}
	return (i);
}

int	start_map(char **lines, int total_lines, int *found_map)
{
	int		i;
	int		counter;
	char	*trimmed;

	i = 0;
	counter = 0;
	*found_map = 0;
	while (i < total_lines)
	{
		if (!lines[i] || is_line_empty(lines[i]))
		{
			i++;
			continue ;
		}
		trimmed = skip_whitespace(lines[i]);
		if (is_config_line(trimmed))
			counter++;
		if (counter == 6)
			return (find_map_start(lines, i + 1, total_lines, found_map));
		i++;
	}
	return (-1);
}
