/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:16:42 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 12:36:05 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(char *str, t_tag tag)
{
	int		len;
	char	spacer;

	if (!str)
		return (0);
	spacer = ' ';
	if (tag.flags & FLAG_ZERO)
		spacer = '0';
	len = 0;
	if (!(tag.flags & FLAG_MINUS))
		len += ft_putnchar(spacer, tag.width - ft_strlen(str), FDOUT);
	len += ft_puts(str, FDOUT);
	if (!*str && tag.type == (t_type)CHAR)
		len += write(FDOUT, "\0", 1);
	if (tag.flags & FLAG_MINUS)
		len += ft_putnchar(spacer, tag.width - ft_strlen(str), FDOUT);
	free(str);
	return (len);
}
