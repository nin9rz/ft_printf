/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:03:49 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/23 15:57:01 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	traitement(char format, long long data)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_putchar('%');
	else if (format == 'c')
		len += ft_putchar((int)data);
	else if (format == 'i' || format == 'd')
		len += ft_putnbr((int)data);
	else if (format == 'u')
		len += ft_putnbr((unsigned int)data);
	else if (format == 'x')
		len += ft_putnbr_base((unsigned long)data, "0123456789abcdef");
	else if (format == 'X')
		len += ft_putnbr_base((unsigned long)data, "0123456789ABCDEF");
	else if (format == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_base((unsigned long)data, "0123456789abcdef");
	}
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
				num += traitement(format[i], va_arg(args, long long));
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