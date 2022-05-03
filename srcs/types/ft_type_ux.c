/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:59:58 by maykman           #+#    #+#             */
/*   Updated: 2022/05/03 17:57:08 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_ux(t_tag tag, va_list args)
{
	char			*s;
	const char		*prefix;
	unsigned int	n;

	n = va_arg(args, unsigned int);

	// Common precision 0 and n 0 special
	if (!n && tag.flags & FLAG_PRECISION && tag.prec == 0)
		s = ft_strdup("");
	else
		s = ft_zutoa_base(n, BASE_HEXA_U);

	// Prefix part
	prefix = NULL;
	if (n && tag.flags & FLAG_HASHTAG)
		prefix = "0X";

	// Common part
	s = filling_zeroes(s, prefix, tag);
	s = ft_addprefix(s, prefix);
	return (ft_print(s, tag));
}
