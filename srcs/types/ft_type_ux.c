/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:59:58 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 19:21:18 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_ux(t_tag tag, va_list args)
{
	char			*s;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	s = ft_zutoa_base(n, BASE_HEXA_U);
	if (n  && tag.flags & FLAG_HASHTAG)
		s = ft_addprefix(s, "0X");
	return (ft_print(s, tag));
}
