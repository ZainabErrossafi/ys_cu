/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:39:14 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 14:39:24 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	pars_no(t_gc *gc, char *line, t_data *data)
{
	if (data->NO_flag)
	{
		printf("ERROR\nNO duplicated\n");
		return (0);
	}
	data->NO_flag = 1;
	return (check_textures(gc, ft_strtrim(gc, line + 3, " \t"),
			&data->north_tex));
}

static int	pars_so(t_gc *gc, char *line, t_data *data)
{
	if (data->SO_flag)
	{
		printf("ERROR\nSO duplicated\n");
		return (0);
	}
	data->SO_flag = 1;
	return (check_textures(gc, ft_strtrim(gc, line + 3, " \t"),
			&data->south_tex));
}

static int	pars_ea(t_gc *gc, char *line, t_data *data)
{
	if (data->EA_flag)
	{
		printf("ERROR\nEA duplicated\n");
		return (0);
	}
	data->EA_flag = 1;
	return (check_textures(gc, ft_strtrim(gc, line + 3, " \t"),
			&data->east_tex));
}

static int	pars_we(t_gc *gc, char *line, t_data *data)
{
	if (data->WE_flag)
	{
		printf("ERROR\nWE duplicated\n");
		return (0);
	}
	data->WE_flag = 1;
	return (check_textures(gc, ft_strtrim(gc, line + 3, " \t"),
			&data->west_tex));
}

int	check_identifier(t_gc *gc, char *line, t_data *data)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (pars_no(gc, line, data));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (pars_so(gc, line, data));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (pars_we(gc, line, data));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (pars_ea(gc, line, data));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (pars_c(line, data));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (pars_f(line, data));
	else
	{
		printf("ERROR\nUndefined identifier\n");
		return (0);
	}
}
