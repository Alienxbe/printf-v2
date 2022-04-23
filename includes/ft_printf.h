/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:12:20 by maykman           #+#    #+#             */
/*   Updated: 2022/04/23 23:39:07 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

// TO REMOVE
#include <stdio.h>

# define FLAG_PRECISION		1
# define FLAG_ZERO			2
# define FLAG_MINUS			4
# define FLAG_HASHTAG		8
# define FLAG_SPACE			16
# define FLAG_PLUS			32
# define FLAGS			"0-# +"
# define TYPES			"cspdiuxX%"
# define NULL_STR		"(null)"

# define FLAG_VAL(pos)	1 << (pos)

typedef enum e_type
{
	NONE = -1,
	CHAR,
	STR,
	PTR,
	D_INT,
	I_INT,
	U_INT,
	LC_HEXA,
	UC_HEXA,
	PCT,
	LENGTH
}	t_type;

typedef struct s_tag
{
	int		flags;
	int		prec;
	int		width;
	t_type	type;
}				t_tag;

/*
** Main functions
*/

int	ft_printf(const char *format, ...);
int	ft_conversion(const char **ptr, va_list args);
t_tag	ft_set_tag(const char **ptr);

/*
** Utils functions
*/

int	ft_puts(const char *s, int fd);
int	ft_index(const char *s, char c);

#endif
