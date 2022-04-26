# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maykman <maykman@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 22:09:09 by maykman           #+#    #+#              #
#    Updated: 2022/04/24 18:54:36 by maykman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC			:=	@gcc
CFLAGS		:=	-Wall -Wextra -Werror
AR			:=	@ar
LFLAGS		:=	-rcs

# COLORS
RED			:=	\033[38;5;9m
GREEN		:=	\033[38;5;10m
BLUE		:= 	\033[38;5;14m
YELLOW		:=	\033[38;5;226m
RESET		:=	\033[38;5;7m
PREFIX		=	[${YELLOW}${FT}${RESET}]\t

# VARIABLES
FT			:=	libftprintf
NAME		:=	${FT}.a
INCLUDES	:=	./includes
LIBFT		:=	./libft

# FILES
SRCS		:=	ft_printf.c \
				ft_conversion.c \
				ft_tag.c
SRCS_UTILS	:=	ft_puts.c \
				ft_index.c \
				ft_todigit.c \
				ft_strtypelen.c \
				ft_cmp_bn.c
OBJS		:=	$(addprefix srcs/, ${SRCS:.c=.o})
OBJS		+=	$(addprefix srcs/utils/, ${SRCS_UTILS:.c=.o})

# RULES
%.o:		%.c
	${CC} ${CFLAGS} -c -I./${INCLUDES} $< -o ${<:.c=.o}
	@echo "${PREFIX}${BLUE}Compilation of $<...${RESET}"

$(NAME):	${OBJS}
	@make NAME=../${NAME} -C ${LIBFT}
	${AR} ${LFLAGS} $@ $^
	@echo "${PREFIX}${GREEN}Library created !${RESET}"

all:		${NAME}

clean:
	@make -C ${LIBFT} clean
	@rm -f ${OBJS}
	@echo "${PREFIX}${YELLOW}Cleaning objects files...${RESET}"

fclean:
	@make -C ${LIBFT} clean
	@rm -f ${NAME} ${OBJS} ${OBJS_BONUS}
	@echo "${PREFIX}${RED}Full clean...${RESET}"

re:			fclean all

install:
	@git clone https://github.com/Alienxbe/LibftProject-v2.git ${LIBFT}

update:
	@git -C ${LIBFT} pull


.PHONY:		all clean fclean re install update
