/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point_d_letters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:40:03 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 15:04:12 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spaces_d_int(int nb, int precision, \
int width, unsigned int *count)
{
	if (width > 0)
		ft_print_spaces_point_int(nb, precision, width, count);
	else
		ft_print_spaces_point_int(nb, precision, -width, count);
}

int	ft_point_dash_c(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;
	char	c;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	c = (char)va_arg(param, int);
	ft_putchar(c, count);
	ft_print_spaces(width, 0, 1, count);
	return (i);
}

int	ft_point_dash_s(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;
	int		precision;
	char	*str;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	str = (char *)va_arg(param, char *);
	if (!str)
		str = "(null)";
	ft_print_d_letters(precision, str, count);
	if (width < 0)
		width = -width;
	if (precision >= 0 && precision < ft_strlen(str))
		ft_print_spaces(width, precision, 0, count);
	else
		ft_print_spaces(width, 0, ft_strlen(str), count);
	return (i);
}

int	ft_point_dash_percent(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width < 0)
		width = -width;
	ft_putchar('%', count);
	ft_print_spaces(width, 0, 1, count);
	return (i);
}

int	ft_point_dash(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	unsigned int	copy;

	copy = i;
	while (format[copy] != 'c' && format[copy] != 's' && format[copy] != 'p'
		&& format[copy] != 'd' && format[copy] != 'i' && format[copy] != 'u'
		&& format[copy] != 'x' && format[copy] != 'X' && format[copy] != '%')
		copy++;
	if (format[copy] == 'd' || format[copy] == 'i')
		i = ft_point_dash_int(format, i, param, count);
	else if (format[copy] == 'u')
		i = ft_point_dash_uns(format, i, param, count);
	else if (format[copy] == 'x')
		i = ft_point_dash_x(format, i, param, count);
	else if (format[copy] == 'X')
		i = ft_point_dash_xmaj(format, i, param, count);
	else if (format[copy] == 'p')
		i = ft_point_dash_p(format, i, param, count);
	else if (format[copy] == 'c')
		i = ft_point_dash_c(format, i, param, count);
	else if (format[copy] == 's')
		i = ft_point_dash_s(format, i, param, count);
	else if (format[copy] == '%')
		i = ft_point_dash_percent(format, i, param, count);
	return (i);
}
