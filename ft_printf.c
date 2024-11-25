/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:03:49 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/25 17:03:20 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptrs(int len, va_list data)
{
	unsigned long	ptr = va_arg(data, unsigned long);
	if (ptr == 0)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += putnbr_base(ptr, "0123456789abcdef");
	}
	return (len);
}

static int	traitement(char format, va_list data)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_putchar('%');
	else if (format == 'c')
		len += ft_putchar(va_arg(data, int));
	else if (format == 'i' || format == 'd')
		len += ft_putnbr(va_arg(data, int));
	else if (format == 'u')
		len += ft_putnbr(va_arg(data, unsigned int));
	else if (format == 'x')
		len += putnbr_base(va_arg(data, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += putnbr_base(va_arg(data, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		len += ptrs(len, data);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		num;
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	num = 0;
	while (format[i])
	{
		if (format[i] != '%')
			num += ft_putchar(format[i]);
		else
		{
			i++;
			if (format[i] == 's')
				num += ft_putstr(va_arg(args, char *));
			else
				num += traitement(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (num);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	ft_printf("%d\n", ft_printf("%x\n", atoi(av[1])));
	return (0);
}
*/