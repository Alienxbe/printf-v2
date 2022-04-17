/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:53:24 by maykman           #+#    #+#             */
/*   Updated: 2022/04/17 21:37:32 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_flags(const char **ptr)
{
	int		flags;
	char	*pos;

	flags = 0;
	pos = ft_strchr(FLAGS, **ptr);
	while (pos)
	{
		flags += FLAG_VAL((pos - FLAGS + 1));
		pos = ft_strchr(FLAGS, *++*ptr);
	}
	if (**ptr == '.')
		flags += FLAG_PRECISION;
	return (flags);
}

t_tag	ft_set_tag(const char **ptr, va_list args)
{
	t_tag	tag;

	tag.flags = ft_get_flags(ptr);
	if (tag.flags & FLAG_PRECISION)
	tag.prec = ft_get_prec(ptr);
	return (tag);
}
