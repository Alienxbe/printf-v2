/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:53:24 by maykman           #+#    #+#             */
/*   Updated: 2022/05/05 23:53:09 by maykman          ###   ########.fr       */
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
		flags |= 1 << (index + 1);
		index = ft_index(FLAGS, *++*format);
	}
	return (flags);
}

static int	ft_getwidth(const char **format)
{
	int	width;

	if (ft_cmp_bn(*format, INT_MAX_STR) > 0)
		width = 0;
	else
		width = ft_atoi(*format);
	*format += ft_strtypelen(*format, &ft_isdigit);
	return (width);
}

static int	ft_getprec(const char **format, t_tag *tag)
{
	int	prec;

	if (**format != '.')
		return (FT_PRINTF_ERROR);
	if (ft_cmp_bn(++*format, INT_MAX_STR) > 0)
		prec = FT_PRINTF_ERROR;
	else
	{
		tag->flags |= FLAG_PRECISION;
		prec = ft_atoi(*format);
	}
	*format += ft_strtypelen(*format, &ft_isdigit);
	return (prec);
}

/*
** remove flag space if flag plus is active
** remove flag zero if there is a precision and type is intger
*/
static int	ft_checktag(t_tag *tag)
{
	if (tag->type == (t_type)NONE)
		return (1);
	if (tag->flags & FLAG_MINUS && tag->flags & FLAG_ZERO)
		tag->flags ^= FLAG_ZERO;
	if (ft_strchr(INTEGER_TYPES, TYPES[tag->type])
		&& tag->flags & FLAG_ZERO && tag->flags & FLAG_PRECISION)
		tag->flags ^= FLAG_ZERO;
	return (0);
}

t_tag	ft_set_tag(int fd, const char **format)
{
	t_tag	tag;

	++*format;
	tag.flags = ft_getflags(format);
	tag.width = ft_getwidth(format);
	tag.prec = ft_getprec(format, &tag);
	tag.fd = fd;
	tag.type = (t_type)ft_index(TYPES, **format);
	if (ft_checktag(&tag))
		tag.type = (t_type)NONE;
	else
		(*format)++;
	return (tag);
}
