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

#include "ft_printf.h"

static int ft_printf_aux(const char *str, va_list arguments, int i, int count)
{
    if (str[i] == '%') {
        count += ft_putchar_fd('%', 1);
    }
    else if (str[i] == 'c') {
        count += ft_putchar_fd((char)va_arg(arguments, int), 1);
    }
    else if (str[i] == 's') {
        count += ft_putstr_fd(va_arg(arguments, char *), 1);
    }
    else if (str[i] == 'p') {
        count += ft_putpointer_fd(va_arg(arguments, unsigned long int), 1);
    }
    else if (str[i] == 'i' || str[i] == 'd') {
        count += ft_putnbr_fd(va_arg(arguments, int), 1);
    }
    else if (str[i] == 'u') {
        count += ft_putunsignednbr_fd(va_arg(arguments, unsigned int), 1);
    }
    else if (str[i] == 'X' || str[i] == 'x') {
        count += ft_put_lowerhexa_fd(va_arg(arguments, int), str[i], 0);
    }
    else {
        count += write(1, &str[i], 2);
    }
    return (count);
}

static int ft_putstr(const char *str, va_list arguments)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            count = ft_printf_aux(str, arguments, i, count);
            i++;
        }
        else {
            count += write(1, &str[i], 1);
            i++;
        }
    }
    return (count);
}

int ft_printf(const char *str, ...)
{
    int count;

    va_list arguments;
    va_start(arguments, str);
    count = ft_putstr(str, arguments);
    va_end(arguments);
    return (count);
}
int main()
{
    // int x = 3;
    int n;
    int m;
    // printf("\n O: %% \n");
    // printf("\n N: %d \n", printf("\n O: %% \n"));
    // ft_printf("\n123 %%");
    // printf("\n N2: %d \n", ft_printf("\n123 %%"));

    // printf("\n  O:  %c \n", 'z');
    // printf("\n N: %d \n", printf("\n  O:  %c \n", 'z'));
    // ft_printf("\n%c", 'z');
    // printf("\n N2: %d \n", ft_printf("\n%c", 'z'));

    // printf("\n  O:  %s \n", "word");
    // printf("\n N: %d \n", printf("\n  O:  %s \n", "word"));
    // ft_printf("\n%s", "word");
    // printf("\n N2: %d \n", ft_printf("\n%s", "word"));

    n = printf("%x", -146);
    printf("\n%d\n", n);
    m = ft_printf("%x", -146);
    printf("\n%d\n", m);

    // printf("\n  O:  %X \n", 11);
    // printf("\n N: %d \n", printf("\n  O:  %X \n", 11));
    // ft_printf("\n%X", 11);
    // printf("\n N2: %d \n", ft_printf("\n%X", 11));

    // printf("\n  O:  %i \n", -10);
    // printf("\n N: %d \n", printf("\n  O:  %i \n", -10));
    // ft_printf("\n%i", -10);
    // printf("\n N2: %d \n", ft_printf("\n%i", -10));

    // printf("\n  O:  %d \n", -10);
    // printf("\n N: %d \n", printf("\n  O:  %d \n", -10));
    // ft_printf("\n%d", -10);
    // printf("\n N2: %d \n", ft_printf("\n%d", -10));

    // printf("\n  O:  %u \n", 10);
    // printf("\n N: %d \n", printf("\n  O:  %u \n", 10));
    // ft_printf("\n%u", 10);
    // printf("\n N2: %d \n", ft_printf("\n%u", 10));
    
    // n = printf("%p", &x);
    // printf("\n N: %d", n);
    // m = ft_printf("%p", &x);
    // printf("\n N2: %d", n);
}