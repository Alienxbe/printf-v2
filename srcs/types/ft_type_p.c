/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:50:12 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 19:07:53 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_p(t_tag tag, va_list args)
{
	char	*s;

	s = ft_zutoa_base(va_arg(args, size_t), BASE_HEXA_L);
	filling_zeroes(&s, "0x", tag);
	return (ft_print(ft_addprefix(s, "0x"), tag));
}
