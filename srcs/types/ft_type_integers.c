/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:24:27 by maykman           #+#    #+#             */
/*   Updated: 2022/05/04 01:02:47 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_integer(t_type type, va_list args)
{
	if (type == D_INT || type == I_INT)
		return (va_arg(args, int));
	else if (type == U_INT || type == LC_HEXA || type == UC_HEXA)
		return (va_arg(args, unsigned int));
	return (va_arg(args, size_t));
}

static const char	*get_base(t_type type)
{
	if (type == LC_HEXA || type == PTR)
		return (BASE_HEXA_L);
	else if (type == UC_HEXA)
		return (BASE_HEXA_U);
	return (BASE_DECI);
}

static char	*get_string(size_t n, t_tag tag)
{
	const char	*base;

	base = get_base(tag.type);
	if (!n && tag.flags & FLAG_PRECISION && tag.prec == 0)
		return (ft_strdup(""));
	if (tag.type == D_INT || tag.type == D_INT)
		retrun (ft_zutoa_base((int)n, base));
	if (tag.type == )
}

static const char	*get_prefix(size_t n, int flags, t_type type)
{
	if (type == D_INT || type == I_INT)
	{
		if ((int)n < 0)
			return ("-");
		else if (flags & FLAG_PLUS)
			return ("+");
		else if (flags & FLAG_SPACE)
			return (" ");
	}
	if (n && flags & FLAG_HASHTAG)
	{
		if (type == LC_HEXA)
			return ("0x");
		else if (type == UC_HEXA)
			return ("0X");
	}
	if (type == PTR)
		return ("0x");
	return (NULL);
}

/*
** This function regroup these types : `pdiuxX`
*/
int	ft_type_integers(t_tag tag, va_list args)
{
	char		*s;
	const char	*prefix;
	size_t		n;

	n = get_integer(tag.type, args);
	s = get_string(n, tag.type);
	prefix = get_prefix(n, tag.flags, tag.type);
	s = ft_addprefix(filling_zeroes(s, prefix, tag), prefix);
	return (ft_print(s, tag));
}
