/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point_letters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:41:45 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/28 10:05:41 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point_c(const char *format, unsigned int i, \
		va_list param, unsigned int *count)
{
	int		width;
	char	c;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	c = (char)va_arg(param, int);
	if (width > 0)
		ft_print_spaces(width, 0, 1, count);
	ft_putchar(c, count);
	if (width < 0)
		ft_print_spaces(-width, 0, 1, count);
	return (i);
}

void	ft_print_spaces_point_s(int precision, char *str, \
		int width, unsigned int *count)
{
	if (precision < ft_strlen(str))
		ft_print_spaces(width, precision, 0, count);
	else
		ft_print_spaces(width, 0, ft_strlen(str), count);
}

int	ft_point_s(const char *format, unsigned int i, \
		va_list param, unsigned int *count)
{
	int		width;
	int		precision;
	char	*str;
	int		j;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	precision = ft_precision_point(format, i, param, &i);
	str = (char *)va_arg(param, char *);
	if (!str)
		str = "(null)";
	if (precision < 0)
		precision = ft_strlen(str);
	ft_print_spaces_point_s(precision, str, width, count);
	j = -1;
	while (++j < precision && str[j])
		ft_putchar(str[j], count);
	if (precision <= ft_strlen(str) && width < 0)
		ft_print_spaces(-width, precision, 0, count);
	else if (precision > ft_strlen(str) && width < 0)
		ft_print_spaces(-width, 0, ft_strlen(str), count);
	return (i);
}

int	ft_point_percent(const char *format, unsigned int i, \
		va_list param, unsigned int *count)
{
	int		width;

	width = 0;
	if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
		width = ft_calcul_width(format, i, param, &i);
	if (width > 0)
		ft_print_spaces(width, 0, 1, count);
	ft_putchar('%', count);
	if (width < 0)
		ft_print_spaces(-width, 0, 1, count);
	return (i);
}

int	ft_point_specifier(const char *format, unsigned int i, \
		va_list param, unsigned int *count)
{
	unsigned int	copy;

	copy = i;
	while (format[copy] != 'c' && format[copy] != 's' && format[copy] != 'p'
		&& format[copy] != 'd' && format[copy] != 'i' && format[copy] != 'u'
		&& format[copy] != 'x' && format[copy] != 'X' && format[copy] != '%')
		copy++;
	if (format[copy] == 'd' || format[copy] == 'i')
		i = ft_point_int(format, i, param, count);
	else if (format[copy] == 'u')
		i = ft_point_uns(format, i, param, count);
	else if (format[copy] == 'x')
		i = ft_point_x(format, i, param, count);
	else if (format[copy] == 'X')
		i = ft_point_xmaj(format, i, param, count);
	else if (format[copy] == 'p')
		i = ft_point_p(format, i, param, count);
	else if (format[copy] == 'c')
		i = ft_point_c(format, i, param, count);
	else if (format[copy] == 's')
		i = ft_point_s(format, i, param, count);
	else if (format[copy] == '%')
		i = ft_point_percent(format, i, param, count);
	return (i);
}
