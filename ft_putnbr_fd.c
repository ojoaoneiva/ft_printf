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

int	ft_putnbr_fd(int nb, int fd, int count)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (count + 11);
	}
	if (nb < 0)
	{
		count += write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		count = ft_putnbr_fd(nb / 10, fd, count);
	nb = (nb % 10) + 48;
	count += write(fd, &nb, 1);
	return (count);
}
