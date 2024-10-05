/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:59:12 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/28 20:18:54 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa_fd(unsigned int nb, char s, int count)
{
	if (nb >= 16)
		count += ft_put_hexa_fd(nb / 16, s, count);
	nb = nb % 16;
	if (nb <= 9)
		nb = nb + '0';
	else if (s == 'x')
		nb = nb - 10 + 'a';
	else
		nb = nb - 10 + 'A';
	count += write(1, &nb, 1);
	return (count);
}
