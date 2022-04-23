/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:53:24 by maykman           #+#    #+#             */
/*   Updated: 2022/04/24 00:07:48 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getflags(const char **format)
{
	int	flags;
	int	index;

	flags = 0;
	index = ft_index(FLAGS, **format);
	while (index >= 0)
	{
		flags += FLAG_VAL(index + 1);
		index = ft_index(FLAGS, *++*format);
	}
	return (flags);
}

/*
** What if number is bigger than : 2147483638 ?
*/
static int	ft_getwidth(char **format)
{
	int	width;

	width = ft_atoi(*format);
	return (width);
}

t_tag	ft_set_tag(const char **format)
{
	t_tag	tag;

	tag.flags = ft_getflags(format);
	tag.width = ft_getwidth(format);
	tag.prec = -1;
	tag.type = (t_type)NONE;
	return (tag);
}
