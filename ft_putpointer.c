/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:59:12 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/28 20:15:21 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa_2(unsigned long int nb, int count)
{
	char	x;

	if (nb >= 16)
		count += ft_put_hexa_2(nb / 16, count);
	nb = nb % 16;
	if (nb <= 9)
		x = nb + '0';
	else
		x = nb - 10 + 'a';
	count += 1;
	write(1, &x, 1);
	return (count);
}

int	ft_putpointer(unsigned long int nb)
{
	int	count;

	count = 0;
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = ft_put_hexa_2(nb, count);
	return (count + 2);
}
