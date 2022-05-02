/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:53:17 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 14:17:30 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addprefix(char *s, const char *prefix)
{
	char	*new;

	if (!s || !prefix)
		return (s);
	new = ft_strjoin(prefix, s);
	free(s);
	return (new);
}
