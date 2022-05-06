/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:06:47 by maykman           #+#    #+#             */
/*   Updated: 2022/05/05 23:02:00 by maykman          ###   ########.fr       */
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
	un = n;
	if (n < 0)
		un = -n;
	prefix = get_prefix(n, tag.flags);
	s = precision_condition(un, tag, BASE_DECI);
	s = filling_zeroes(s, prefix, tag);
	s = ft_addprefix(s, prefix);
	return (ft_print(s, tag));
}
