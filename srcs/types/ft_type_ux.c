/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:40:21 by maykman           #+#    #+#             */
/*   Updated: 2022/05/05 23:41:03 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_ux(t_tag tag, va_list args)
{
	char			*s;
	const char		*prefix;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	prefix = NULL;
	if (n && tag.flags & FLAG_HASHTAG)
		prefix = "0X";
	s = precision_condition(n, tag, BASE_HEXA_U);
	s = filling_zeroes(s, prefix, tag);
	s = ft_addprefix(s, prefix);
	return (ft_print(s, tag));
}
