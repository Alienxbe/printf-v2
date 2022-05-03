/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:21:54 by maykman           #+#    #+#             */
/*   Updated: 2022/05/03 17:49:59 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_u(t_tag tag, va_list args)
{
	unsigned int	n;
	char			*s;

	n = va_arg(args, unsigned int);

	// Common precision 0 and n 0 special
	if (!n && tag.flags & FLAG_PRECISION && tag.prec == 0)
		s = ft_strdup("");
	else
		s = ft_zutoa_base(n, BASE_DECI);

	// Prefix part
	// (Never add prefix)

	// Common part
	s = filling_zeroes(s, NULL, tag);
	return (ft_print(s, tag));
}
