/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:51:27 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 14:52:31 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game *g)
{
	try_move(g, g->player.dir_x * MOVE_SPEED, g->player.dir_y * MOVE_SPEED);
}

void	move_backward(t_game *g)
{
	try_move(g, -g->player.dir_x * MOVE_SPEED, -g->player.dir_y * MOVE_SPEED);
}

void	move_left(t_game *g)
{
	try_move(g, -g->player.plane_x * MOVE_SPEED, -g->player.plane_y
		* MOVE_SPEED);
}

void	move_right(t_game *g)
{
	try_move(g, g->player.plane_x * MOVE_SPEED, g->player.plane_y * MOVE_SPEED);
}
