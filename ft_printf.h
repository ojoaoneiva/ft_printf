/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:13 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/28 20:18:28 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr_fd(int nb, int fd, int count);
int	ft_putpointer(unsigned long int nb);
int	ft_put_hexa_fd(unsigned int nb, char s, int count);
int	ft_putunsignednbr_fd(unsigned int nb, int fd, int count);
int	ft_putstr(const char *str);
int	ft_printf(const char *str, ...);

#endif
