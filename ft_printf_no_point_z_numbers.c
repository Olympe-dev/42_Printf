/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_point_z_numbers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:29:39 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 15:02:00 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_point_zero_int(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int			width;
	int			nb;
	long long	big_nb;

	width = 0;
	while (format[i] == '0')
		i++;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (int)va_arg(param, int);
	if (nb < 0)
		ft_putchar('-', count);
	if (nb >= 0)
		ft_print_zeros(width, ft_get_size(nb), count);
	else
		ft_print_zeros(width, ft_get_size(nb) + 1, count);
	big_nb = ft_nb_negative(nb);
	ft_putnbr(big_nb, count);
	if (width < 0 && nb >= 0)
		ft_print_spaces(-width, 0, ft_get_size(nb), count);
	else
		ft_print_spaces(-width, 0, ft_get_size(nb) + 1, count);
	return (i);
}

int	ft_no_point_zero_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	width = 0;
	while (format[i] == '0')
		i++;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_zeros(width, ft_get_size(nb), count);
	ft_putnbr(nb, count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size(nb), count);
	return (i);
}

int	ft_no_point_zero_x(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	width = 0;
	while (format[i] == '0')
		i++;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_zeros(width, ft_get_size_hexa(nb), count);
	ft_to_hexa(nb, "0123456789abcdef", count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size_hexa(nb), count);
	return (i);
}

int	ft_no_point_zero_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	width = 0;
	while (format[i] == '0')
		i++;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned int)va_arg(param, unsigned int);
	if (width > 0)
		ft_print_zeros(width, ft_get_size_hexa(nb), count);
	ft_to_hexa(nb, "0123456789ABCDEF", count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size_hexa(nb), count);
	return (i);
}

int	ft_no_point_zero_p(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int					width;
	unsigned long int	nb;

	width = 0;
	while (format[i] == '0')
		i++;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	nb = (unsigned long int)va_arg(param, unsigned long int);
	ft_putstr("0x", count);
	if (width > 0)
		ft_print_zeros(width, ft_get_size_hexa(nb) + 2, count);
	ft_to_hexa(nb, "0123456789abcdef", count);
	if (width < 0)
		ft_print_spaces(-width, 0, ft_get_size_hexa(nb) + 2, count);
	return (i);
}
