/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:03:49 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/18 15:12:15 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	traitement(char format, long long data, int len)
{
	if (format == '%')
		len += ft_putchar('%');
	if (format == 'c')
		len += ft_putchar((int)data);
	if (format == 'i' || format == 'd')
		len += ft_putnbr((int)data);
	if (format == 'u')
		len += ft_putnbr((unsigned int)data);
	if (format == 'x')
		len += ft_putnbr_base((unsigned long)data, "0123456789abcdef");
	if (format == 'X')
		len += ft_putnbr_base((unsigned long)data, "0123456789ABCDEF");
	if (format == 'p')
		len += ft_putnbr_base((unsigned long)data, "0123456789ABCDEF");
	return (len);
}

int			ft_printf(const char *format, ...)
{
	int		num;
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
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
				num = traitement(format[i],  va_arg(args, long long), num);
		}
		i++;
	}
	va_end(args);
	return (num);
}

int		main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_base(atoi(argv[1]), "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(atoi(argv[1]), "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(atoi(argv[1]), "0123456789ABCDEF");
	write(1, "\n", 1);
}