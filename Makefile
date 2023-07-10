# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 16:37:47 by tzanchi           #+#    #+#              #
#    Updated: 2023/07/10 15:06:19 by tzanchi          ###   ########.fr        #
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
				perform_rotations.c \
				push_between_stacks.c \
				sort_function.c \
				utils_cost_calculation.c \
				utils_stack_manip.c \
				utils_standard.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

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
				rm -f ${LIBFT}

re:				fclean all

.PHONY:			all clean fclean re
