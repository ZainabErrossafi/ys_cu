#include "../cub3d.h"

int count_map_lines(char **lines, int start, int total_lines)
{
    int count;
    int i;
    
    count = 0;
    i = start;
    while (i < total_lines)
    {
        if (is_line_empty(lines[i]))
            break;
        count++;
        i++;
    }
    return (count);
}

int check_after_map(char **lines, int map_end, int total_lines)
{
    int i;
    
    i = map_end;
    while (i < total_lines)
    {
        if (!is_line_empty(lines[i]))
        {
            printf("Error\nContenu invalide après la map à la ligne %d\n", i + 1);
            return (0);
        }
        i++;
    }
    return (1);
}
t_map	*init_map_struct(t_gc *gc)
{
	t_map	*map;

	map = gc_malloc(gc, sizeof(t_map));
	if (!map)
		return (NULL);
	map->player_x = -1;
	map->player_y = -1;
	map->player_dir = 0;
	map->map_width = 0;
	map->grid = NULL;
	return (map);
}
