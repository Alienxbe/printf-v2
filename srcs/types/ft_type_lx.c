/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_lx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:28:12 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 19:15:55 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_lx(t_tag tag, va_list args)
{
	char			*s;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	s = ft_zutoa_base(n, BASE_HEXA_L);
	if (!n  && tag.flags & FLAG_HASHTAG)
		s = ft_addprefix(s, "0x");
	return (ft_print(s, tag));
}
