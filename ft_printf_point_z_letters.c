/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point_z_letters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:38:14 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/28 10:09:45 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_zeros_z_int(int precision, int nb, \
int width, unsigned int *count)
{
	if (precision > 0)
		ft_print_zeros(precision, ft_get_size(nb), count);
	else if (precision < 0 && nb >= 0)
		ft_print_zeros(width, ft_get_size(nb), count);
	else if (precision < 0 && nb < 0)
		ft_print_zeros(width, ft_get_size(nb) + 1, count);
}

int	ft_point_zero_c(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;
	int		precision;
	char	c;

	while (format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	c = (char)va_arg(param, int);
	if (width > 0)
		ft_print_zeros(width, 1, count);
	ft_putchar(c, count);
	if (width < 0)
		ft_print_spaces(-width, precision, 1, count);
	return (i);
}

int	ft_point_zero_s(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;
	int		precision;
	char	*str;
	int		j;

	while (format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	str = (char *)va_arg(param, char *);
	if (!str)
		str = "(null)";
	if (precision < 0)
		precision = ft_strlen(str);
	ft_print_zeros(width, ft_strlen(str), count);
	j = -1;
	while (++j < precision && str[j])
		ft_putchar(str[j], count);
	if (precision < ft_strlen(str) && width < 0)
		ft_print_spaces(-width, precision, 0, count);
	else if (precision > ft_strlen(str) && width < 0)
		ft_print_spaces(-width, 0, ft_strlen(str), count);
	return (i);
}

int	ft_point_zero_percent(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;

	while (format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width > 0)
		ft_print_zeros(width, 1, count);
	ft_putchar('%', count);
	if (width < 0)
		ft_print_spaces(-width, 0, 1, count);
	return (i);
}

int	ft_point_zero(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	unsigned int	copy;

	copy = i;
	while (format[copy] != 'c' && format[copy] != 's' && format[copy] != 'p'
		&& format[copy] != 'd' && format[copy] != 'i' && format[copy] != 'u'
		&& format[copy] != 'x' && format[copy] != 'X' && format[copy] != '%')
		copy++;
	if (format[copy] == 'd' || format[copy] == 'i')
		i = ft_point_zero_int(format, i, param, count);
	else if (format[copy] == 'u')
		i = ft_point_zero_uns(format, i, param, count);
	else if (format[copy] == 'x')
		i = ft_point_zero_x(format, i, param, count);
	else if (format[copy] == 'X')
		i = ft_point_zero_xmaj(format, i, param, count);
	else if (format[copy] == 'p')
		i = ft_point_zero_p(format, i, param, count);
	else if (format[copy] == 'c')
		i = ft_point_zero_c(format, i, param, count);
	else if (format[copy] == 's')
		i = ft_point_zero_s(format, i, param, count);
	else if (format[copy] == '%')
		i = ft_point_zero_percent(format, i, param, count);
	return (i);
}
