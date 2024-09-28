/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:59:12 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/28 20:19:54 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignednbr_fd(unsigned int nb, int fd, int count)
{
	if (nb >= 10)
	{
		count = ft_putunsignednbr_fd(nb / 10, fd, count);
	}
	nb = (nb % 10) + 48;
	count += write(fd, &nb, 1);
	return (count);
}
/*
int main()
{
	ft_putnbr_fd(-10, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(142, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	return (0);
}*/
