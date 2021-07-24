# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:00:38 by thhusser          #+#    #+#              #
#    Updated: 2021/07/24 21:38:23 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			
BONUS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strcpy.c \
			ft_strncat.c \
			ft_strcmp.c \
			ft_strstr.c \
			ft_memdel.c \
			ft_memalloc.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_putchar.c \
			ft_strnew.c \
			ft_strclr.c \
			ft_strdel.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_putendl.c \
			get_next_line.c \

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	= ${BONUS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

HEADER	=	-I libft/libft.h

.c.o:
			@gcc ${CFLAGS} -c $< -o $(<:.c=.o) ${HEADER}

${NAME}:	${OBJS}
			@gcc $(FLAGS) -c $(SRCS)
			@ar rcs ${NAME} ${OBJS}

bonus:
			@gcc $(FLAGS) -c $(SRCS) $(BONUS)
			@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

all:		${NAME}

clean:	
			@${RM} ${OBJS} $(BONUS:.c=.o)

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
