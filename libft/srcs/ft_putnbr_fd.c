/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:26:20 by mykman            #+#    #+#             */
/*   Updated: 2022/03/19 17:32:09 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -n;
	}
	if (un >= 10)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd('0' + un % 10, fd);
}
