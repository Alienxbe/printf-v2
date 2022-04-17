/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:15:27 by maykman           #+#    #+#             */
/*   Updated: 2022/04/17 20:53:15 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	const char	*ptr;
	va_list		args;
	int			len;

	va_start(args, format);
	ptr = ft_strchr(format, '%');
	len = 0;
	while (ptr)
	{
		len += write(1, format, ptr - format);
		format = ptr + 1;
		// Conversion here
		ptr = ft_strchr(format, '%');
	}
	va_end(args);
	if (ptr != format)
		len += write(1, format, ft_strlen(format));
	return (len);
}
