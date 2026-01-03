/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:36:34 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 14:36:36 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	validate_map_start(char **lines, int total_lines, int *start)
{
	int	found_map;

	*start = start_map(lines, total_lines, &found_map);
	if (*start == -1)
		return (0);
	if (!found_map || *start >= total_lines)
		return (0);
	return (1);
}

static int	calculate_max_width(char **lines, int start, int height)
{
	int	i;
	int	len;
	int	max_width;

	max_width = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(lines[start + i]);
		if (len > 0 && lines[start + i][len - 1] == '\n')
			len--;
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

static void	fill_map_line(char *dest, char *src, int max_width)
{
	int	j;
	int	len;

	len = ft_strlen(src);
	if (len > 0 && src[len - 1] == '\n')
		len--;
	j = 0;
	while (j < len)
	{
		dest[j] = src[j];
		j++;
	}
	while (j < max_width)
	{
		dest[j] = ' ';
		j++;
	}
	dest[max_width] = '\0';
}

static int	allocate_and_fill_grid(t_gc *gc, t_map *map, char **lines,
		int start)
{
	int	i;

	map->grid = gc_malloc(gc, sizeof(char *) * (map->map_height + 1));
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->map_height)
	{
		map->grid[i] = gc_malloc(gc, sizeof(char) * (map->map_width + 1));
		if (!map->grid[i])
			return (0);
		fill_map_line(map->grid[i], lines[start + i], map->map_width);
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

t_map	*extract_map(t_gc *gc, char **lines, int total_lines)
{
	t_map	*map;
	int		start;
	int		actual_map_lines;

	if (!lines || !*lines)
		return (printf("Error\nFichier vide ou invalide\n"), NULL);
	map = init_map_struct(gc);
	if (!map)
		return (NULL);
	if (!validate_map_start(lines, total_lines, &start))
		return (NULL);
	actual_map_lines = count_map_lines(lines, start, total_lines);
	if (actual_map_lines <= 0)
		return (NULL);
	if (!check_after_map(lines, start + actual_map_lines, total_lines))
		return (NULL);
	map->map_height = actual_map_lines;
	map->map_width = calculate_max_width(lines, start, map->map_height);
	if (!allocate_and_fill_grid(gc, map, lines, start))
		return (NULL);
	return (map);
}
