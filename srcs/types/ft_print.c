/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:16:42 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 02:40:37 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_c_null(char *str, t_tag tag)
{
	if (!*str && tag.type == (t_type)CHAR)
		return (write(FDOUT, "\0", 1));
	return (0);
}

int	ft_print(char *str, t_tag tag)
{
	int	len;

	(void)tag;
	if (!str)
		return (0);
	len = 0;
	if (!(tag.flags & FLAG_MINUS))
		len += ft_putnchar(' ', tag.width - ft_strlen(str), FDOUT);
	len += ft_puts(str, FDOUT);
	if (tag.flags & FLAG_MINUS)
		len += ft_putnchar(' ', tag.width - ft_strlen(str), FDOUT);
	len += type_c_null(str, tag);
	free(str);
	return (len);
}