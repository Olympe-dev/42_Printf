/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spaces_zeroes_letters.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:31 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/31 12:03:33 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spaces(int width, int precision, int size, unsigned int *count)
{
	if (precision < size)
	{
		while (width - size > 0)
		{
			ft_putchar(' ', count);
			size++;
		}
	}
	else
	{
		while (width - precision > 0)
		{
			ft_putchar(' ', count);
			precision++;
		}
	}
}

void	ft_print_zeros(int precision, int size, unsigned int *count)
{
	while (precision - size > 0)
	{
		ft_putchar('0', count);
		size++;
	}
}

void	ft_print_d_letters(int precision, char *str, unsigned int *count)
{
	int	j;

	j = 0;
	if (precision >= 0)
	{
		while (str[j] && j < precision)
		{
			ft_putchar(str[j], count);
			j++;
		}
	}
	else
	{
		while (str[j])
		{
			ft_putchar(str[j], count);
			j++;
		}
	}
}
