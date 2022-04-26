/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:11:33 by maykman           #+#    #+#             */
/*   Updated: 2022/04/26 20:18:14 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	ft_printf("Bonjour : %123d :D\n", "OUIOUI BAGUETTE");
	// char	s[] = "Bonjour";

	// (void)s;
	// printf("%p\n", s);
	// printf("%#llx\n", (long long)s);
	printf("%d\n", printf("%6516516515616321516516515651651561651c\n", 'c'));
	return (0);
}

