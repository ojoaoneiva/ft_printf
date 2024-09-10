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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putnbrp_fd(int nb, int fd);
void	ft_put_upperhexa_fd(int nb, int fd);
void	ft_put_lowerhexa_fd(int nb, int fd);
void	ft_putdecnbr_fd(int nb, int fd);
void	ft_putunsignednbr_fd(unsigned int nb, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif