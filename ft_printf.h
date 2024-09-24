/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:13 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/05/29 14:13:05 by jneiva-s         ###   ########.fr       */
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

int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int nb, int fd);
int	ft_putpointer_fd(unsigned long int nb, int fd);
int	ft_put_lowerhexa_fd(int nb, char s, int count);
int	ft_putunsignednbr_fd(unsigned int nb, int fd);
int	ft_putstr_fd(const char *str, int fd);
int ft_printf(const char *str, ...);

#endif