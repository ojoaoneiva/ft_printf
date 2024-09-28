/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:41:20 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/28 19:55:41 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		str = "(null)";
	if (!fd)
		return (-1);
	while (str[i] != '\0')
	{
		count += write(fd, &str[i], 1);
		i++;
	}
	return (count);
}

// int	main() {
// 	char x[] = "abcd";
// 	ft_putstr_fd(x,0);
// }
