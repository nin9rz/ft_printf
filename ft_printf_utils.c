/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:17 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/18 16:00:23 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base(long long int n, char *base)
{
	char			c;
	long long int	len;

	len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
		ft_putnbr_base(n % len, base);
	}
	if (n < len)
	{
		c = base[n % len];
		write(1, &c, 1);
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = (nb < 0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + '0');
	return (len);
}
