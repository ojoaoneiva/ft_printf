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

int	ft_put_lowerhexa_fd2(unsigned long int nb, int fd, int count)
{
	char x;
	if (nb >= 16)
	{
		count += 1;
		ft_put_lowerhexa_fd2(nb / 16, fd, count);
	}
	
	nb = nb % 16;
	if (nb<=9){
		x = nb + '0';
	} else {
		x = nb - 10 + 'a';
	}
	count += write(fd, &x, 1);
	return(count);
}

int	ft_putpointer_fd(unsigned long int nb, int fd) {
	int	count;
	count = write(fd, "0x", 2);
	count += ft_put_lowerhexa_fd2(nb, fd, count);
	return(count*3);
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