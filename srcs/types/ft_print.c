/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:16:42 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 02:13:04 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	free(str);
	return (len);
}
