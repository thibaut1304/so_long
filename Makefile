# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 20:36:41 by thhusser          #+#    #+#              #
#    Updated: 2021/07/24 20:36:41 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

FLAGS 		= -Wall -Wextra -Werror

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})

SRCS_FILES	= 	main.c \
				parser/check_borders.c \
				parser/maps.c \
				error.c \
				memory.c \
				parser/begin.c \
				utils/utils.c \
				init.c \
				key_events/key_events.c \
				utils/mlx_utils.c \
				display.c \
				images.c \
				textures.c \
				player.c \
				memory_2.c \
				
				

PATH_LIBFT 	= ./libft/

PATH_MLX	= ./minilibx/

HEADER		= -I ./includes

OBJS		= ${SRCS:.c=.o}

RM 			= rm -f

# PENSER A RETIRER LE MODE DEBUG -g
.c.o:
			@gcc -g ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME): 	${OBJS}
			@make bonus -C libft/
			@gcc -g $(FLAGS) $(HEADER) $(OBJS) -o $(NAME) -L ${PATH_LIBFT} -lft -L ${PATH_MLX} -lmlx -lXext -lX11 -lm

ex:			${NAME}
			./${NAME} maps/map.ber

ev:			${NAME}		
			@~/.local/bin/colour-valgrind -v --show-leak-kinds=all --tool=memcheck --leak-check=full  --track-origins=yes ./${NAME} maps/map.ber

clean:	
			${RM} ${OBJS}
			@make clean -C libft/

fclean:		clean
			${RM} ${NAME}
			@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re