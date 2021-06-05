/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spaces_zeroes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:18:11 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 14:25:07 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spaces_point_int(long long nb, \
int precision, int width, unsigned int *count)
{
	if (nb >= 0)
	{
		if (precision < ft_get_size(nb))
			ft_print_spaces(width, 0, ft_get_size(nb), count);
		else
			ft_print_spaces(width, precision, 0, count);
	}
	else
	{
		if (precision < ft_get_size(nb))
			ft_print_spaces(width, 0, ft_get_size(nb) + 1, count);
		else
			ft_print_spaces(width, precision + 1, 0, count);
	}
}

void	ft_print_spaces_point_x(long long nb, \
int precision, int width, unsigned int *count)
{
	if (nb >= 0)
	{
		if (precision < ft_get_size_hexa(nb))
			ft_print_spaces(width, 0, ft_get_size_hexa(nb), count);
		else
			ft_print_spaces(width, precision, 0, count);
	}
	else
	{
		if (precision < ft_get_size_hexa(nb))
			ft_print_spaces(width, 0, ft_get_size_hexa(nb) + 1, count);
		else
			ft_print_spaces(width, precision + 1, 0, count);
	}
}

void	ft_print_spaces_point_p(long long nb, \
int precision, int width, unsigned int *count)
{
	if (nb > 0 && precision >= 0)
	{
		if (precision < ft_get_size_hexa(nb) + 2)
			ft_print_spaces(width, 0, ft_get_size_hexa(nb) + 2, count);
		else
			ft_print_spaces(width, precision + 2, 0, count);
	}
	else if (nb == 0 && precision >= 0)
	{
		if (precision < ft_get_size_hexa(nb) + 1)
			ft_print_spaces(width, 0, ft_get_size_hexa(nb) + 1, count);
		else
			ft_print_spaces(width, precision + 1, 0, count);
	}
	else if (nb < 0 && precision >= 0)
	{
		if (precision < ft_get_size_hexa(nb) + 2)
			ft_print_spaces(width, 0, ft_get_size_hexa(nb) + 3, count);
		else
			ft_print_spaces(width, precision + 3, 0, count);
	}
}
