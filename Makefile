# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 09:55:46 by mde-sa--          #+#    #+#              #
#    Updated: 2024/05/13 13:18:30 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   cub3D

CC      = 	cc

CFLAGS   =  -Wall -Wextra -Werror -g

SRCDIR	=	src

INCDIR	=   includes

LIBFTDIR =  src/libft

MLXDIR  = 	minilibx-linux

SRC		=	main.c misc/usage_check.c misc/clean_memory.c \
			parser/main_parser.c parser/header_parser.c parser/texture_parser.c \
			parser/colour_parser.c parser/map_parser.c parser/create_map_tab.c \
			parser/check_map_boundaries.c parser/map_cleaner.c parser/trim_map.c \
			simulation/run_cub3d.c simulation/vector_init.c simulation/create_image.c \
			simulation/hooks.c simulation/movements.c simulation/looking.c \
			simulation/textures.c raycast/camera_plane.c raycast/compute_vector_data.c \
			raycast/check_intersection.c misc/my_pixel_put.c

LIBS 	=   -L$(LIBFTDIR) -lft

MLXLIBS =   -L$(MLXDIR) -lmlx -lXext -lX11

MATHLIBS =  -lm

OBJS	= 	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))

RM      = 	rm -rf

INCFLAGS =  -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR)


all: libft minilibx $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXLIBS) $(MATHLIBS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h $(MLXDIR)/*.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

libft:
	cd $(LIBFTDIR) && make

minilibx:
	cd minilibx-linux && make

clean:
	$(MAKE) -sC $(LIBFTDIR) clean
	cd minilibx-linux && make clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -sC $(LIBFTDIR) fclean
	cd minilibx-linux && make clean
	$(RM) $(NAME)

re: fclean all

download:
	wget https://cdn.intra.42.fr/document/document/22624/minilibx-linux.tgz
	tar -xzf minilibx-linux.tgz
	rm minilibx-linux.tgz

.PHONY: all clean fclean re libft minilibx download