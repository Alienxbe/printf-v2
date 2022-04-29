/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:59:58 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 01:02:41 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_ux(t_tag tag, va_list args)
{
	char	*s;

	s = ft_utoa_base(va_arg(args, unsigned int), BASE_HEXA_U);
	return (ft_print(s, tag));
}
