/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:12:51 by mykman            #+#    #+#             */
/*   Updated: 2022/03/14 19:42:28 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = ft_calloc(ft_strlen(s) + 1, sizeof(*cpy));
	if (!cpy)
		return (NULL);
	return (ft_memcpy(cpy, s, ft_strlen(s)));
}
