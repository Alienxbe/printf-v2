/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:12:20 by maykman           #+#    #+#             */
/*   Updated: 2022/05/05 23:41:41 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define FDOUT				STDOUT_FILENO

# define FLAG_PRECISION		1
# define FLAG_ZERO			2
# define FLAG_MINUS			4
# define FLAG_HASHTAG		8
# define FLAG_SPACE			16
# define FLAG_PLUS			32
# define FLAGS				"0-# +"
# define TYPES				"cspdiuxX%"
# define INTEGER_TYPES		"diuxX"
# define NULL_STR			"(null)"
# define INT_MAX_STR		"2147483647"

# define BASE_DECI			"0123456789"
# define BASE_HEXA_L		"0123456789abcdef"
# define BASE_HEXA_U		"0123456789ABCDEF"

# define FT_PRINTF_ERROR	-1

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
}	t_tag;

typedef int	(*t_print)(t_tag, va_list);

/*
** Main functions
*/

int		ft_printf(const char *format, ...);
int		ft_conversion(const char **format, va_list args);
t_tag	ft_set_tag(const char **format);

/*
** Types functions
*/

int		ft_print(char *str, t_tag tag);
int		ft_type_c(t_tag tag, va_list args);
int		ft_type_s(t_tag tag, va_list args);
int		ft_type_p(t_tag tag, va_list args);
int		ft_type_d(t_tag tag, va_list args);
int		ft_type_i(t_tag tag, va_list args);
int		ft_type_u(t_tag tag, va_list args);
int		ft_type_lx(t_tag tag, va_list args);
int		ft_type_ux(t_tag tag, va_list args);
int		ft_type_pct(t_tag tag, va_list args);

/*
** Utils functions
*/

int		ft_puts(const char *s, int fd);
int		ft_putnchar(char c, int n, int fd);
int		ft_index(const char *s, char c);
int		ft_todigit(char c);
int		ft_cmp_bn(const char *n1, const char *n2);
size_t	ft_strtypelen(const char *s, int (*istype)(int));
char	*ft_ctoa(char c);
char	*ft_zutoa_base(size_t n, const char *base);
char	*ft_addprefix(char *s, const char *prefix);

char	*filling_zeroes(char *s, const char *prefix, t_tag tag);
char	*precision_condition(size_t n, t_tag tag, const char *base);

#endif
