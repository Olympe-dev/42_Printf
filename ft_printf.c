/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:04:16 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/31 13:45:22 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_point(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	if (format[i] == '0' && format[i + 1] != '-')
		i = ft_no_point_zero(format, i, param, count);
	else if (format[i] == '-' || format[i + 1] == '-')
		i = ft_no_point_dash(format, i, param, count);
	else if ((format[i] == '0' && format[i + 1] == '-')
		|| (format[i] == '-' && format[i + 1] == '0'))
		i = ft_no_point_dash(format, i + 2, param, count);
	else
		i = ft_no_point_specifier(format, i, param, count);
	return (i);
}

int	ft_point(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	if (format[i] == '0' && format[i + 1] != '-')
		i = ft_point_zero(format, i + 1, param, count);
	else if (format[i] == '-' && format[i + 1] != '0')
		i = ft_point_dash(format, i + 1, param, count);
	else if ((format[i] == '0' && format[i + 1] == '-')
		|| (format[i] == '-' && format[i + 1] == '0'))
		i = ft_point_dash(format, i + 2, param, count);
	else
		i = ft_point_specifier(format, i, param, count);
	return (i);
}

int	ft_percent(const char *format, unsigned int i, \
va_list param, unsigned int *count)
{
	int	point;
	int	copy;

	point = 0;
	copy = i;
	while (format[copy] != 'c' && format[copy] != 's' && format[copy] != 'p'
		&& format[copy] != 'd' && format[copy] != 'i' && format[copy] != 'u'
		&& format[copy] != 'x' && format[copy] != 'X' && format[copy] != '%')
	{
		if (format[copy] == '.')
			point = 1;
		copy++;
	}
	if (point == 0)
		i = ft_no_point(format, i, param, count);
	else
		i = ft_point(format, i, param, count);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			param;

	i = 0;
	count = 0;
	va_start(param, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &count);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%', &count);
			i++;
		}
		else
			i = ft_percent(format, i + 1, param, &count);
		i++;
	}
	va_end(param);
	return (count);
}
