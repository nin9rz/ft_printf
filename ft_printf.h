/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:05:35 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/15 17:41:21 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *, ...);

/* Utils */

void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

/* Putnbr base */

void	ft_putnbr_base(int n, char *base);
int		ft_base(char *base);
int		ft_convert(int n, char *base);

#endif
