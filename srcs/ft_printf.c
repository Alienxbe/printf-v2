/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:15:27 by maykman           #+#    #+#             */
/*   Updated: 2022/04/16 23:12:07 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	const char	*ptr;
	int			len;

	ptr = format;
	len = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			len += write(1, format, ptr - format);
			// call conversion here
			// len += conversion => conversion return length of itself
			// Move ptr at the end of the conversion
			format = ptr;
		}
		ptr++;
	}
	if (ptr != format)
		len += write(1, format, ptr - format);
	return (len);
}
