/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:06:47 by maykman           #+#    #+#             */
/*   Updated: 2022/05/01 16:23:20 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_chars(char *s, unsigned char c, int n)
{
	char	*new;
	size_t	len;

	if (!s || n <= 0)
		return (s);
	len = ft_strlen(s) + n;
	new = ft_calloc(len + 1, sizeof(*new));
	if (new)
	{
		ft_memset(new, c, n);
		ft_memcpy(new + n, s, ft_strlen(s));
	}
	free(s);
	return (new);
}

int	ft_type_d(t_tag tag, va_list args)
{
	char			*s;
	int				n;
	unsigned int	un;

	n = va_arg(args, int);
	un = n;
	if (n < 0)
		un = -n;
	s = ft_zutoa_base(un, BASE_DECI);
	if (tag.flags & FLAG_PRECISION)
		s = add_chars(s, '0', tag.prec - ft_strlen(s));
	else if (tag.flags & FLAG_ZERO)
		s = add_chars(s, '0', tag.width - ft_strlen(s));
	if (n < 0)
		s = ft_addprefix(s, "-");
	else if (n > 0 && tag.flags & FLAG_PLUS)
		s = ft_addprefix(s, "+");
	else if (n > 0 && tag.flags & FLAG_SPACE)
		s = ft_addprefix(s, " ");
	return (ft_print(s, tag));
}
