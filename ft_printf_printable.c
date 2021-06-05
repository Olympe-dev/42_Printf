/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:14:45 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 14:14:47 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, unsigned int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, unsigned int *count)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(long long nb, unsigned int *count)
{
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, count);
	ft_putchar((nb % 10) + '0', count);
}

void	ft_to_hexa(unsigned long long nb, char *base, unsigned int *count)
{
	if (nb > 15)
		ft_to_hexa(nb / 16, base, count);
	write(1, &base[nb % 16], 1);
	(*count)++;
}
