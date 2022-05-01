/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:06:47 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 21:09:20 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_d(t_tag tag, va_list args)
{
	char	*s;
	int		n;

	n = va_arg(args, int);
	s = ft_itoa(n);
	if (n > 0 && tag.flags & FLAG_PLUS)
		s = ft_addprefix(s, "+");
	else if (n > 0 && tag.flags & FLAG_SPACE)
		s = ft_addprefix(s, " ");
	return (ft_print(s, tag));
}
