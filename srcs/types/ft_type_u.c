/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:21:54 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 16:19:14 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_u(t_tag tag, va_list args)
{
	char	*s;

	s = ft_zutoa_base(va_arg(args, unsigned int), BASE_DECI);
	return (ft_print(s, tag));
}
