/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:52:36 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/10 10:58:00 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
# include <stdarg.h>

void	ft_putstr(const char *str, va_list arguments)
{
	int	i = 0;
	while (str[i] != '\0')
	{
        if(str[i] == '%')
        {
            i++;
            if (str[i] == '%'){
                ft_putchar_fd('%',1);
            }
            else if (str[i] == 'c'){
                char char_arg = (char)va_arg(arguments, int);
                ft_putchar_fd(char_arg,1);
            }
            else if (str[i] == 's'){
                char *str_arg = va_arg(arguments, char *);
                ft_putstr_fd(str_arg,1);
            }
            else if (str[i] == 'p'){
                void *s = va_arg(arguments, void *);
                unsigned char *z = (unsigned char *)s;
                int x = (int)z;
                ft_putnbr_fd(x,1);
            }
            else if (str[i] == 'i'){
                int num;
                num = va_arg(arguments, int);
                ft_putnbr_fd(num,1);
            }
            else if (str[i] == 'd'){
                int num;
                num = va_arg(arguments, int);
                ft_putdecnbr_fd(num,1);
            }
            else if (str[i] == 'u'){
                unsigned int num;
                num = va_arg(arguments,unsigned int);
                ft_putunsignednbr_fd(num,1);
            }
            else if (str[i] == 'X'){
                int num;
                num = va_arg(arguments, int);
                ft_put_upperhexa_fd(num,1);
            }
            else if (str[i] == 'x'){
                int num;
                num = va_arg(arguments, int);
                ft_put_lowerhexa_fd(num,1);
            }
            else {
            write(1, &str[i], 2);
            }
            i++;
        } else {
            write(1, &str[i], 1);
            i++;
        }
	}
}
int ft_printf(const char *str, ...){
    va_list arguments;
    va_start(arguments, str);
    ft_putstr(str,  arguments);
    va_end(arguments);
    return(0);
}
int main(){
    char x[] = "abcd";
    //printf("\n Printf original1:    %u \n", -11);
    //printf("\n Printf original2:    %X \n", 11);
    ft_printf("%p",11);
    //ft_printf("%u",11);

    //ft_printf("pdAh%%fgjf %d %u %s %c",-13,49,"word",'z');

}