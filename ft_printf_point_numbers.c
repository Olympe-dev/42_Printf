/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:41:05 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/28 10:08:07 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point_int(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int			width;
	int			precision;
	int			nb;
	long long	big_nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (int)va_arg(param, int);
	if (width > 0)
		ft_print_spaces_point_int(nb, precision, width, count);
	if (nb < 0)
		ft_putchar('-', count);
	ft_print_zeros(precision, ft_get_size(nb), count);
	big_nb = ft_nb_negative(nb);
	if (!(precision == 0 && nb == 0))
		ft_putnbr(big_nb, count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width < 0)
		ft_print_spaces_point_int(nb, precision, -width, count);
	return (i);
}

int	ft_point_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	int				precision;
	unsigned int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_spaces_point_int(nb, precision, width, count);
	ft_print_zeros(precision, ft_get_size(nb), count);
	if (!(precision == 0 && nb == 0))
		ft_putnbr(nb, count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width < 0)
		ft_print_spaces_point_int(nb, precision, -width, count);
	return (i);
}

int	ft_point_x(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	int				precision;
	unsigned int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_print_spaces_point_x(nb, precision, width, count);
	ft_print_zeros(precision, ft_get_size_hexa(nb), count);
	if (!(precision == 0 && nb == 0))
		ft_to_hexa(nb, "0123456789abcdef", count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width < 0)
		ft_print_spaces_point_x(nb, precision, -width, count);
	return (i);
}

int	ft_point_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	int				precision;
	unsigned int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_print_spaces_point_x(nb, precision, width, count);
	ft_print_zeros(precision, ft_get_size_hexa(nb), count);
	if (!(precision == 0 && nb == 0))
		ft_to_hexa(nb, "0123456789ABCDEF", count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width < 0)
		ft_print_spaces_point_x(nb, precision, -width, count);
	return (i);
}

int	ft_point_p(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int					width;
	int					precision;
	unsigned long int	nb;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned long int)va_arg(param, unsigned long int);
	ft_print_spaces_point_p(nb, precision, width, count);
	ft_putstr("0x", count);
	ft_print_zeros(precision, ft_get_size_hexa(nb), count);
	if (!(precision <= 0 && nb == 0))
		ft_to_hexa(nb, "0123456789abcdef", count);
	if (precision < 0 && nb == 0)
		ft_putchar('0', count);
	if (width < 0)
		ft_print_spaces_point_p(nb, precision, -width, count);
	return (i);
}
