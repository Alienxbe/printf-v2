/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:52:38 by maykman           #+#    #+#             */
/*   Updated: 2022/04/26 19:59:42 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char **format, va_list args)
{
	t_tag	tag;

	(void)args;
	tag = ft_set_tag(format);
	ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
	return (0);
}
