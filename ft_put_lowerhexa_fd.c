/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:59:12 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/03/14 17:38:25 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_lowerhexa_fd(unsigned int nb,char s, int count)
{
		ft_put_lowerhexa_fd(nb / 16, s, count);
	return (count);
}

int	ft_put_lowerhexa_fd(int nb,char s, int count)
{
	if (nb < 0) {
		count += 7;
		count += ft_put_unsigned_lowerhexa_fd((unsigned int)nb, s, count);
	}
	if (nb == 0) {
		count += ft_put_lowerhexa_fd((unsigned int)nb, s, count);
	}
	if (nb >= 16)
	{
		count += 1;
		ft_put_lowerhexa_fd(nb / 16, s, count);
	}
	nb = nb % 16;
	if (nb<=9){
		nb = (nb % 10) + 48;
	} else if (s == 'x') {
		nb = (nb % 10) + 'a';
	} else {
		nb = (nb % 10) + 'A';
	}
	count += write(1, &nb, 1);
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