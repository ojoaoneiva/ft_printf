/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:41:20 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/03/13 19:24:07 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		count += write(fd, &str[i], 1);
		i++;
	}
	return(count);
}

// int	main() {
// 	char x[] = "abcd";
// 	ft_putstr_fd(x,0);
// }