# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maykman <maykman@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 22:09:09 by maykman           #+#    #+#              #
#    Updated: 2022/04/29 01:58:39 by maykman          ###   ########.fr        #
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
MAKE_LIBFT	:=	@make -s -C ${LIBFT}

# FILES
SRCS		:=	ft_printf.c \
				ft_conversion.c \
				ft_tag.c
SRCS_TYPES	:=	ft_print.c \
				ft_type_c.c \
				ft_type_s.c \
				ft_type_p.c \
				ft_type_d.c \
				ft_type_u.c \
				ft_type_lx.c \
				ft_type_ux.c \
				ft_type_pct.c
SRCS_UTILS	:=	ft_puts.c \
				ft_index.c \
				ft_todigit.c \
				ft_strtypelen.c \
				ft_cmp_bn.c \
				ft_ctoa.c \
				ft_putnchar.c \
				ft_utoa_base.c \
				ft_addprefix.c
OBJS		:=	$(addprefix srcs/, ${SRCS:.c=.o})
OBJS		+=	$(addprefix srcs/types/, ${SRCS_TYPES:.c=.o})
OBJS		+=	$(addprefix srcs/utils/, ${SRCS_UTILS:.c=.o})

# RULES
%.o:		%.c
	${CC} ${CFLAGS} -c -I./${INCLUDES} $< -o ${<:.c=.o}
	@echo "${PREFIX}${BLUE}Compilation of $<...${RESET}"

$(NAME):	${OBJS}
	${MAKE_LIBFT} NAME=../${NAME}
	${AR} ${LFLAGS} $@ $^
	@echo "${PREFIX}${GREEN}Library created !${RESET}"

all:		${NAME}

clean:
	${MAKE_LIBFT} clean
	@rm -f ${OBJS}
	@echo "${PREFIX}${YELLOW}Cleaning objects files...${RESET}"

fclean:
	${MAKE_LIBFT} clean
	@rm -f ${NAME} ${OBJS} ${OBJS_BONUS}
	@echo "${PREFIX}${RED}Full clean...${RESET}"

re:			fclean all

install:
	@git clone https://github.com/Alienxbe/LibftProject-v2.git ${LIBFT}

update:
	@git -C ${LIBFT} pull


.PHONY:		all clean fclean re install update
