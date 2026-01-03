NAME = cub3D

SRCS = main.c \
       utils/utils.c \
       utils/utils2.c \
       utils/utils3.c \
       parsing/parsing.c \
       parsing/pars.c \
       parsing/pars_utils.c \
       parsing/pars_utils2.c \
       parsing/pars_map.c \
       parsing/pars_map_utils.c \
       parsing/extract_map.c \
       parsing/extract_map_utils.c \
       parsing/extract_map_utils2.c\
       raycasting/raycasting.c \
       raycasting/ray_init.c \
       raycasting/ray_draw.c \
       raycasting/ray_dda.c \
       mouvement/mouvement.c \
       mouvement/mouvement_utils.c \
       mouvement/rotation.c \
       mouvement/hooks.c \
       garbage_collector/garbage_collector.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS =  -L./minilibx-linux/ -lmlx -lXext -lX11 -lm
MATHFLAGS = -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(MATHFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re