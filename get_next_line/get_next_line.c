/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerrossa <zerrossa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:17:50 by zerrossa          #+#    #+#             */
/*   Updated: 2025/12/05 with GC by zerrossa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_all(int fd, char *all, t_gc *gc)
{
    char    *buff;
    char    *tmp;
    ssize_t nbytes;

    buff = (char *)gc_malloc(gc, ((size_t)BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    nbytes = 1;
    while (!(ft_strchr(all, '\n')) && nbytes > 0)
    {
        nbytes = read(fd, buff, BUFFER_SIZE);
        if (nbytes == -1)
        {
            return (NULL);
        }
        if (nbytes == 0)
            break ;
        buff[nbytes] = '\0';
        tmp = ft_strjoin_gc(all, buff, gc);
        all = tmp;
    }
    return (all);
}

static char *get_line(char *all, t_gc *gc)
{
    char    *line;
    int     i;

    i = 0;
    if (!all[i])
        return (NULL);
    while (all[i] && all[i] != '\n')
        i++;
    if (all[i] == '\n')
        i++;
    line = gc_malloc(gc, (i + 1) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (all[i] && all[i] != '\n')
    {
        line[i] = all[i];
        i++;
    }
    if (all[i] == '\n')
    {
        line[i] = all[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char *get_next(char *all, t_gc *gc)
{
    char    *res;
    int     i;
    int     j;

    i = 0;
    while (all[i] && all[i] != '\n')
        i++;
    if (all[i] == '\0')
        return (NULL);
    res = (char *)gc_malloc(gc, (ft_strlen(all) - i + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i++;
    j = 0;
    while (all[i])
    {
        res[j] = all[i];
        j++;
        i++;
    }
    res[j] = '\0';
    return (res);
}

char    *get_next_line(int fd, t_gc *gc)
{
    static char *all;
    char        *line;

    if (fd < 0 || !gc)
        return (NULL);
    all = get_all(fd, all, gc);
    if (!all)
        return (NULL);
    line = get_line(all, gc);
    all = get_next(all, gc);
    return (line);
}