# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 16:37:47 by tzanchi           #+#    #+#              #
#    Updated: 2023/06/30 19:21:51 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	push_swap
LIBFT		=	libft.a

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/

SRC			=	input_validation.c \
				main.c \
				utils.c

TEMP_TEST	=	temp_tests.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

TEST_OBJS	=	${TEMP_TEST:.c=.o}

all:			
				make ${LIBFT}
				make ${NAME}

${LIBFT}:
				make -C ${LIBFT_DIR}
				mv ${LIBFT_DIR}/${LIBFT} .

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${SRCS} -I${HEAD_DIR} ${LIBFT} -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@
				
clean:
				make -C ${LIBFT_DIR} clean
				rm -f ${OBJS}

fclean:			clean
				make -C ${LIBFT_DIR} fclean
				rm -f ${NAME}

re:				fclean all

test:
				make ${LIBFT}
				make ${OBJS} ${TEST_OBJS}
				${CC} ${CFLAGS} ${SRCS} ${TEMP_TEST} -I${HEAD_DIR} ${LIBFT}
				make fclean
				rm -f ${TEST_OBJS}
				clear

.PHONY:			all clean fclean re test
