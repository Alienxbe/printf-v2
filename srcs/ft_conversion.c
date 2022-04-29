/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:52:38 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 02:11:02 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_table(t_print *table)
{
	table[CHAR] = &ft_type_c;
	table[STR] = &ft_type_s;
	table[PTR] = &ft_type_p;
	table[D_INT] = &ft_type_d;
	table[I_INT] = &ft_type_d;
	table[U_INT] = &ft_type_u;
	table[LC_HEXA] = &ft_type_lx;
	table[UC_HEXA] = &ft_type_ux;
	table[PCT] = &ft_type_pct;
}

int	ft_conversion(const char **format, va_list args)
{
	t_print	ft_print[LENGTH];
	t_tag	tag;

	tag = ft_set_tag(format);
	ft_init_table(ft_print);
	return (ft_print[tag.type](tag, args));
}
