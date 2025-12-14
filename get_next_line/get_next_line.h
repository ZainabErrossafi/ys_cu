/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainab <zainab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:51 by zerrossa          #+#    #+#             */
/*   Updated: 2025/12/05 23:45:46 by zainab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../cub3d.h"
// #include "../cub"


// char    *get_next_line(int fd, t_gc *gc);
// size_t  ft_strlen(char *str);
// char    *ft_strchr(char *s, int c);
char    *ft_strjoin_gc(char *s1, char *s2, t_gc *gc);

// char	*get_next_line(int fd);
// char	*ft_strchr(char *s, int c);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(char *str);

#endif