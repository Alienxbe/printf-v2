/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:53:24 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 02:51:18 by maykman          ###   ########.fr       */
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

static int	ft_getwidth(const char **format)
{
	int	width;

	if (ft_cmp_bn(*format, MAX_WIDTH_STR) > 0)
		return (FT_PRINTF_ERROR);
	width = ft_atoi(*format);
	*format += ft_strtypelen(*format, &ft_isdigit);
	return (width);
}

static int	ft_getprec(const char **format, t_tag *tag)
{
	int	prec;

	if (**format != '.')
		return (FT_PRINTF_ERROR);
	tag->flags += FLAG_PRECISION;
	if (ft_cmp_bn(++*format, MAX_PREC_STR) > 0)
		return (FT_PRINTF_ERROR);
	prec = ft_atoi(*format);
	*format += ft_strtypelen(*format, &ft_isdigit);
	return (prec);
}

static int	ft_checktag(t_tag tag)
{
	if (tag.width == FT_PRINTF_ERROR)
		return (1);
	if (tag.flags & FLAG_PRECISION && tag.prec == FT_PRINTF_ERROR)
		return (1);
	if (tag.type == (t_type)NONE)
		return (1);
	return (0);
}

t_tag	ft_set_tag(const char **format)
{
	t_tag	tag;

	++*format;
	tag.flags = ft_getflags(format);
	tag.width = ft_getwidth(format);
	tag.prec = ft_getprec(format, &tag);
	tag.type = (t_type)ft_index(TYPES, **format);
	if (ft_checktag(tag))
		tag.type = (t_type)NONE;
	else
		(*format)++;
	return (tag);
}
