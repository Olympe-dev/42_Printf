/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point_d_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:39:15 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 15:25:33 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point_dash_int(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int			width;
	int			precision;
	int			nb;
	long long	big_nb;

	i = ft_go_ahead(format, i, '-', '0');
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	while (format[i] != '.')
		i++;
	precision = ft_precision_point(format, i, param, &i);
	nb = (int)va_arg(param, int);
	if (nb < 0)
		ft_putchar('-', count);
	ft_print_zeros(precision, ft_get_size(nb), count);
	big_nb = ft_nb_negative(nb);
	if (!(precision == 0 && nb == 0))
		ft_putnbr(big_nb, count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	ft_print_spaces_d_int(nb, precision, width, count);
	while (format[i] != 'd' && format[i] != 'i')
		i++;
	return (i);
}

int	ft_point_dash_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	int				precision;
	unsigned int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_print_zeros(precision, ft_get_size(nb), count);
	if (!(precision == 0 && nb == 0))
		ft_putnbr(nb, count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width > 0)
		ft_print_spaces_point_int(nb, precision, width, count);
	else
		ft_print_spaces_point_int(nb, precision, -width, count);
	return (i);
}

int	ft_point_dash_x(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	int				precision;
	unsigned int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_print_zeros(precision, ft_get_size_hexa(nb), count);
	if (!(precision == 0 && nb == 0))
		ft_to_hexa(nb, "0123456789abcdef", count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width > 0)
		ft_print_spaces_point_x(nb, precision, width, count);
	else
		ft_print_spaces_point_x(nb, precision, -width, count);
	return (i);
}

int	ft_point_dash_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	int				precision;
	unsigned int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_print_zeros(precision, ft_get_size_hexa(nb), count);
	if (!(precision == 0 && nb == 0))
		ft_to_hexa(nb, "0123456789ABCDEF", count);
	else if (width != 0 && precision == 0 && nb == 0)
		ft_putchar(' ', count);
	if (width > 0)
		ft_print_spaces_point_x(nb, precision, width, count);
	else
		ft_print_spaces_point_x(nb, precision, -width, count);
	return (i);
}

int	ft_point_dash_p(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int					width;
	int					precision;
	unsigned long int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	precision = ft_precision_point(format, i, param, &i);
	nb = (unsigned long int)va_arg(param, unsigned long int);
	ft_putstr("0x", count);
	ft_print_zeros(precision, ft_get_size_hexa(nb), count);
	if (!(precision <= 0 && nb == 0))
		ft_to_hexa(nb, "0123456789abcedf", count);
	ft_print_spaces_point_p(nb, precision, width, count);
	return (i);
}
