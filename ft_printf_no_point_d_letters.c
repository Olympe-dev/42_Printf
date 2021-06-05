/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_point_d_letters.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:32:47 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/27 14:50:31 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_point_dash_c(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;
	char	c;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	c = (char)va_arg(param, int);
	ft_putchar(c, count);
	if (width < 0)
		width = -width;
	ft_print_spaces(width, 0, 1, count);
	return (i);
}

int	ft_no_point_dash_s(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;
	char	*str;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	str = (char *)va_arg(param, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str, count);
	if (width < 0)
		width = -width;
	ft_print_spaces(width, 0, ft_strlen(str), count);
	return (i);
}

int	ft_no_point_dash_percent(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int		width;

	while (format[i] == '-' || format[i] == '0')
		i++;
	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	ft_putchar('%', count);
	if (width < 0)
		width = -width;
	ft_print_spaces(width, 0, 1, count);
	return (i);
}

int	ft_no_point_dash(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	unsigned int	copy;

	copy = i;
	while (format[copy] != 'c' && format[copy] != 's' && format[copy] != 'p'
		&& format[copy] != 'd' && format[copy] != 'i' && format[copy] != 'u'
		&& format[copy] != 'x' && format[copy] != 'X' && format[copy] != '%')
		copy++;
	if (format[copy] == 'd' || format[copy] == 'i')
		i = ft_no_point_dash_int(format, i, param, count);
	else if (format[copy] == 'u')
		i = ft_no_point_dash_uns(format, i, param, count);
	else if (format[copy] == 'x')
		i = ft_no_point_dash_x(format, i, param, count);
	else if (format[copy] == 'X')
		i = ft_no_point_dash_xmaj(format, i, param, count);
	else if (format[copy] == 'p')
		i = ft_no_point_dash_p(format, i, param, count);
	else if (format[copy] == 'c')
		i = ft_no_point_dash_c(format, i, param, count);
	else if (format[copy] == 's')
		i = ft_no_point_dash_s(format, i, param, count);
	else if (format[copy] == '%')
		i = ft_no_point_dash_percent(format, i, param, count);
	return (i);
}
