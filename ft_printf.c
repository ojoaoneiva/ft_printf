/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:52:36 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/09/28 20:16:40 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_aux(const char *str, va_list arguments, int i, int count)
{
	if (str[i] == '%')
		count += ft_putchar_fd('%', 1);
	else if (str[i] == 'c')
		count += ft_putchar_fd(va_arg(arguments, int), 1);
	else if (str[i] == 's')
		count += ft_putstr_fd(va_arg(arguments, char *), 1);
	else if (str[i] == 'p')
		count += ft_putpointer_fd(va_arg(arguments, unsigned long int), 1);
	else if (str[i] == 'i' || str[i] == 'd')
		count += ft_putnbr_fd(va_arg(arguments, int), 1, 0);
	else if (str[i] == 'u')
		count += ft_putunsignednbr_fd(va_arg(arguments, unsigned int), 1, 0);
	else if (str[i] == 'X' || str[i] == 'x')
		count += ft_put_hexa_fd(va_arg(arguments, unsigned int), str[i], 0);
	else
		count += write(1, &str[i], 2);
	return (count);
}

static int	ft_putstr(const char *str, va_list arguments)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count = ft_printf_aux(str, arguments, i, count);
			i++;
		}
		else
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		arguments;

	if (!str)
		return (-1);
	va_start(arguments, str);
	count = ft_putstr(str, arguments);
	va_end(arguments);
	return (count);
}
// int main()
// {
//     int x = 15;
//     char *s_erro = NULL;
//     int m;
//     int n;

//     // %% %c %s 
//     n = printf("test percentage, c, s: %% %c %s", 'c', "hello");
//     printf("\n N: %d", n);
//     m = ft_printf("test percentage, c, s: %% %c %s", 'c', "hello");
//     printf("\n N2: %d\n\n", m);

//     // %c %s null 
//     n = printf("test null c, s: %c %s", '\0', s_erro);
//     printf("\n N: %d", n);
//      m = ft_printf("test null c, s: %c %s", '\0', s_erro);
//     printf("\n N2: %d\n\n", m);

//     // %u %i &d negative
//     n = printf("test -u, -i, -d: %u %i %d", -2, -2, -2);
//     printf("\n N: %d", n);
//     m = ft_printf("test -u, -i, -d: %u %i %d", -2, -2, -2);
//     printf("\n N2: %d\n\n", m);

//     // %u %i &d
//     n = printf("test u, i, d: %u %i %d", 34, 34, 34);
//     printf("\n N: %d", n);
//     m = ft_printf("test u, i, d: %u %i %d", 34, 34, 34);
//     printf("\n N2: %d\n\n", m);

//     // %x %X 0
//     n = printf("test x, X: %x %X", 0, 0);
//     printf("\n N: %d", n);
//      m = ft_printf("test x, X: %x %X", 0, 0);
//     printf("\n N2: %d\n\n", m);

//     // %x %X 
//     n = printf("test x, X: %x %X", 15, 15);
//     printf("\n N: %d", n);
//     m = ft_printf("test x, X: %x %X", 15, 15);
//     printf("\n N2: %d\n\n", m);

//     // %x %X negative
//     n = printf("test -x, -X: %x %X", -255, -255);
//     printf("\n N: %d", n);
//     m = ft_printf("test -x, -X: %x %X", -255, -255);
//     printf("\n N2: %d\n\n", m);

//     // %p
//     n = printf("%p", &x);
//     printf("\n N: %d", n);
//     m = ft_printf("%p", &x);
//     printf("\n N2: %d\n\n", m);

//     // %p NULL
//     n = printf("%p", NULL);
//     printf("\n N: %d", n);
//     m = ft_printf("%p", NULL);
//     printf("\n N2: %d\n\n", m);

//     return 0;
// }

// int main()
// {
// ft_printf(0);
// return 0;
// }
