/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:14:40 by zerrossa          #+#    #+#             */
/*   Updated: 2025/12/05 with GC by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin_gc(char *s1, char *s2, t_gc *gc)
{
    size_t  len1;
    size_t  len2;
    char    *res;
    int     i;

    i = 0;
    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    res = gc_malloc(gc, (len1 + len2 + 1) * sizeof(char));
    if (!res)
        return (NULL);
    while (*s1)
        res[i++] = *s1++;
    while (*s2)
        res[i++] = *s2++;
    res[i] = '\0';
    return (res);
}