/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:50:12 by maykman           #+#    #+#             */
/*   Updated: 2022/05/05 22:52:45 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_p(t_tag tag, va_list args)
{
	char	*s;
	size_t	n;

	n = va_arg(args, size_t);
	s = precision_condition(n, tag, BASE_HEXA_L);
	s = filling_zeroes(s, "0x", tag);
	s = ft_addprefix(s, "0x");
	return (ft_print(s, tag));
}
