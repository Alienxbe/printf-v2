/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:11:33 by maykman           #+#    #+#             */
/*   Updated: 2022/04/16 23:04:12 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("(%d)\n", printf("Bonjour a %%tous les amis\n"));
	printf("(%d)\n", ft_printf("Bonjour a %tous les amis\n"));
	return 0;
}

