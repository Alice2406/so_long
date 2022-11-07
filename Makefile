# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:25:30 by aniezgod          #+#    #+#              #
#    Updated: 2022/11/07 18:08:23 by aniezgod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ----------------------------------COLORS------------------------------------#

BOLD = \e[1;37m
END = \e[0;37m
UNDER = \e[4;37m
GREY = \e[0;30m
RED = \e[0;31m
GREEN = \e[0;32m
YELLOW = \e[0;33m
BLUE = \e[0;34m
PURPLE = \e[0;35m
CYAN = \e[0;36m
WHITE = \e[0;37m

SRCS =	./srcs/so_long.c \
		./srcs/check_map.c \
		./srcs/ft_error.c \
		./srcs/check_char_map.c \
		./srcs/check_wall.c \
		./srcs/set_map.c \
		./srcs/move_player.c \
		./srcs/check_way.c \
		./srcs/init_struct.c \
		./srcs/bonus_player.c \

OBJS = ${SRCS:.c=.o}

NAME = so_long
CC = clang
CFLAGS = -Wall -Wextra -Werror
SYSTEM = $(shell uname)
RM = rm -f

ifeq (${SYSTEM}, Darwin)
INCS = -I ./includes -I ./libft/includes/ -I ./mlx_mac
LIBC =  -L ./mlx_mac -lmlx -L ./libft -lft
MLX_FLAGS = -Ofast -framework OpenGL -framework AppKit
MLX_USED = mlx_mac
HEADER_MESSAGE = COMPILATION SUR ${RED}MACOS${END}
endif

ifeq (${SYSTEM}, Linux)
INCS = -I ./includes -I ./libft/includes -I ./mlx_linux
LIBC = -L ./mlx_linux -L ./libft
MLX_FLAGS	=	-L./mlx_linux -lX11 -lbsd -lXext -lm
MLX_USED = mlx_linux
HEADER_MESSAGE = COMPILATION SUR ${RED}LINUX${END}
endif

all: ${NAME}

.c.o:
			@${CC} ${FLAGS} ${INCS} -c $< -o $@

$(NAME): $(OBJS)
			@printf "[${HEADER_MESSAGE}]\n"
			@printf "${WHITE}${BOLD}╔════════════════════════════════════════════════════════════════════════════╗\n"
			@printf "${BOLD}║                              .: COMPILATION :.                             ║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"
			@${MAKE} -C ./libft >/dev/null
			@printf "${BOLD}║                                    ${PURPLE}libft                                   ${WHITE}║\n"
			@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
			@printf "${BOLD}║                                     ${PURPLE}mlx                                    ${WHITE}║\n"
			@${CC} ${FLAGS} ${INCS} ${MLX_FLAGS} -o ${NAME} ${OBJS} ${LIBC} libft/libft.a mlx_linux/libmlx.a
			@printf "${BOLD}║                                   ${PURPLE}${NAME}                                  ${WHITE}║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"

clean:
			@${RM} ${OBJS}
			@${MAKE} -C libft clean >/dev/null
			@${MAKE} -C ${MLX_USED} clean >/dev/null
			@rm -f ${OBJS}

			
fclean: clean
			@printf "${BOLD}Entreprise de nettoyage bonjour ?\n"
			@${RM} ${NAME}
			@${MAKE} -C libft fclean >/dev/null
			@printf "${BOLD}${GREEN}Tout est propre !✨\n"

re: fclean all

.PHONY:		all clean fclean re