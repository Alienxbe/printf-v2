/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:06:47 by maykman           #+#    #+#             */
/*   Updated: 2022/05/03 18:04:36 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*get_prefix(int n, int flags)
{
	if (n < 0)
		return ("-");
	else if (flags & FLAG_PLUS)
		return ("+");
	else if (flags & FLAG_SPACE)
		return (" ");
	return (NULL);
}

int	ft_type_d(t_tag tag, va_list args)
{
	char			*s;
	const char		*prefix;
	int				n;
	unsigned int	un;

	n = va_arg(args, int);

	// Sign part
	un = n;
	if (n < 0)
		un = -n;

	// Common precision 0 and n 0 special
	if (!n && tag.flags & FLAG_PRECISION && tag.prec == 0)
		s = ft_strdup("");
	else
		s = ft_zutoa_base(un, BASE_DECI);

	// Prefix part
	prefix = get_prefix(n, tag.flags);

	// Common part
	s = filling_zeroes(s, prefix, tag);
	s = ft_addprefix(s, prefix);
	return (ft_print(s, tag));
}
