/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:15:27 by maykman           #+#    #+#             */
/*   Updated: 2022/04/23 23:14:55 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	const char	*ptr;
	va_list		args;
	int			len;

	len = 0;
	va_start(args, format);
	ptr = ft_strchr(format, '%');
	while (ptr)
	{
		len += write(STDOUT_FILENO, format, ptr - format);
		format = ptr + 1;
		len += ft_conversion(&format, args);
		ptr = ft_strchr(format, '%');
	}
	if (format != ptr)
		len += ft_puts(format, STDOUT_FILENO);
	va_end(args);
	return (len);
}
