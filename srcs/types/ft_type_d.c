/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:06:47 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 18:26:26 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_d(t_tag tag, va_list args)
{
	char			*s;
	const char		*prefix;
	int				n;
	unsigned int	un;

	n = va_arg(args, int);
	un = n;
	if (n < 0)
		un = -n;
	prefix = NULL;
	if (n < 0)
		prefix = "-";
	else if (tag.flags & FLAG_PLUS)
		prefix = "+";
	else if (tag.flags & FLAG_SPACE)
		prefix = " ";
	if (!n && tag.flags & FLAG_PRECISION && tag.prec == 0)
		s = ft_strdup("");
	else
		s = ft_zutoa_base(un, BASE_DECI);
	filling_zeroes(&s, prefix, tag);
	s = ft_addprefix(s, prefix);
	return (ft_print(s, tag));
}
