/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:11:33 by maykman           #+#    #+#             */
/*   Updated: 2022/05/07 00:40:52 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define PARAMS	"|%0230d|\n", 315651

int main(void)
{
	/*ft_printf("yours : %d\n", ft_printf(PARAMS));
	printf("Origi : %d\n", printf(PARAMS));*/
	char	nom[] = "Mathieu";

	ft_printf("Bonjour %s\n", nom);
	return (0);
}
