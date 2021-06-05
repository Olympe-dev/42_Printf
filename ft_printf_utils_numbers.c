/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:08:55 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 14:09:56 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calcul_width(const char *format, unsigned int i, \
va_list param, unsigned int *ptr_i)
{
	int	width;

	width = 0;
	if (format[i] == '*')
	{
		width = (int)va_arg(param, int);
		i++;
	}
	else
	{
		while (format[i] != 'c' && format[i] != 's' && format[i] != 'p'
			&& format[i] != 'd' && format[i] != 'i' && format[i] != 'u'
			&& format[i] != 'x' && format[i] != 'X' && format[i] != '.'
			&& format[i] != '%')
			width = width * 10 + (format[i++] - '0');
	}
	*ptr_i = i;
	return (width);
}

int	ft_get_size(long long nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (10);
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_get_size_hexa(long long unsigned nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

long	ft_nb_negative(int nb)
{
	long	nbr_long;

	nbr_long = (long)nb;
	if (nbr_long < 0)
		nbr_long = -nbr_long;
	return (nbr_long);
}
