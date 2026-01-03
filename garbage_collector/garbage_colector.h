/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_colector.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:02:54 by zerrossa          #+#    #+#             */
/*   Updated: 2026/01/03 15:02:55 by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>

typedef struct s_gc_node
{
	void				*ptr;
	struct s_gc_node	*next;
}						t_gc_node;

typedef struct s_gc
{
	t_gc_node			*head;
}						t_gc;

t_gc					*gc_init(void);
void					*gc_malloc(t_gc *gc, size_t size);
void					gc_free_all(t_gc *gc);
void					gc_remove_ptr(t_gc *gc, void *ptr);

#endif