/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:15:27 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 02:51:30 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(const char *format)
{
	if (!format)
		return (1);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_set_tag(&format).type == (t_type)NONE)
				return (1);
		}
		else
			format++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	const char	*ptr;
	va_list		args;
	int			len;

	if (ft_checkformat(format))
		return (-1);
	len = 0;
	va_start(args, format);
	ptr = ft_strchr(format, '%');
	while (ptr)
	{
		len += write(FDOUT, format, ptr - format);
		format = ptr;
		len += ft_conversion(&format, args);
		ptr = ft_strchr(format, '%');
	}
	if (!ptr)
			len += ft_puts(format, FDOUT);
	va_end(args);
	return (len);
}
