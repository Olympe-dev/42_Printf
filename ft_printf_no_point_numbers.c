/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_point_numbers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:33:51 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/31 12:00:21 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_point_int(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int	width;
	int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (int)va_arg(param, int);
	if (nb >= 0 && width >= 0)
		ft_print_spaces(width, 0, ft_get_size(nb), count);
	else if (nb < 0 && width >= 0)
		ft_print_spaces(width, 0, ft_get_size(nb) + 1, count);
	ft_putnbr(nb, count);
	if (nb >= 0 && width < 0)
		ft_print_spaces(-width, 0, ft_get_size(nb), count);
	else if (nb < 0 && width < 0)
		ft_print_spaces(-width, 0, ft_get_size(nb) + 1, count);
	return (i);
}

int	ft_no_point_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_spaces(width, 0, ft_get_size(nb), count);
	ft_putnbr(nb, count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size(nb), count);
	return (i);
}

int	ft_no_point_x(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_spaces(width, 0, ft_get_size_hexa(nb), count);
	ft_to_hexa(nb, "0123456789abcdef", count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size_hexa(nb), count);
	return (i);
}

int	ft_no_point_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_spaces(width, 0, ft_get_size_hexa(nb), count);
	ft_to_hexa(nb, "0123456789ABCDEF", count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size_hexa(nb), count);
	return (i);
}

int	ft_no_point_p(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int					width;
	unsigned long int	ptr;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	ptr = (unsigned long int)va_arg(param, unsigned long int);
	if (width > 0)
		ft_print_spaces(width, 0, ft_get_size_hexa(ptr) + 2, count);
	ft_putstr("0x", count);
	ft_to_hexa(ptr, "0123456789abcdef", count);
	if (width < 0 && (-width) > (ft_get_size_hexa(ptr) + 2))
		ft_print_spaces(-width, 0, ft_get_size_hexa(ptr) + 2, count);
	return (i);
}
