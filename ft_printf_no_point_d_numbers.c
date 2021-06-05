/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_point_d_numbers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:31:46 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 14:53:52 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_point_dash_int(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int	width;
	int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	nb = (int)va_arg(param, int);
	ft_putnbr(nb, count);
	if (nb >= 0 && width >= 0)
		ft_print_spaces(width, 0, ft_get_size(nb), count);
	else if (nb < 0 && width >= 0)
		ft_print_spaces(width, 0, ft_get_size(nb) + 1, count);
	return (i);
}

int	ft_no_point_dash_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_putnbr(nb, count);
	ft_print_spaces(width, 0, ft_get_size(nb), count);
	return (i);
}

int	ft_no_point_dash_x(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_to_hexa(nb, "0123456789abcdef", count);
	ft_print_spaces(width, 0, ft_get_size_hexa(nb), count);
	return (i);
}

int	ft_no_point_dash_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int				width;
	unsigned int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	nb = (unsigned int)va_arg(param, unsigned int);
	ft_to_hexa(nb, "0123456789ABCDEF", count);
	ft_print_spaces(width, 0, ft_get_size_hexa(nb), count);
	return (i);
}

int	ft_no_point_dash_p(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int					width;
	unsigned long int	nb;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	nb = (unsigned long int)va_arg(param, unsigned long int);
	ft_putstr("0x", count);
	ft_to_hexa(nb, "0123456789abcdef", count);
	ft_print_spaces(width, 0, ft_get_size_hexa(nb) + 2, count);
	return (i);
}
