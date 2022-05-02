/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:05:30 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 18:32:18 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_chars(char *s, unsigned char c, int n)
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

void	filling_zeroes(char **s, const char *prefix, t_tag tag)
{
	tag.width -= ft_strlen(prefix);
	if (tag.flags & FLAG_PRECISION)
		*s = add_chars(*s, '0', tag.prec - ft_strlen(*s));
	else if (tag.flags & FLAG_ZERO)
		*s = add_chars(*s, '0', tag.width - ft_strlen(*s));
}
