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


#include <stdio.h>

int main()
{
	int count = 0;
	int min = -2147483648;			// d and i
	int zero = 0;					// d and i and u and x and X
	int max = 2147483647;			// d and i and u and x and X
	unsigned int uns = 4294967295;	// u and x and X
	int *ptr_min = &min;			// p
	int *ptr_max = &max;			// p
	char c = 'a';					// c
	char *str = "bonjour";			// s
	char *nul = NULL;				// s


	//////////	A FEW GENERAL RANDOM TESTS	//////////

    count = ft_printf("mine: %10.20d|%10.20d|%10.20d print after\n", min, zero, max);
  	printf("count mine: %d\n", count);
    count = printf("real: %10.20d|%10.20d|%10.20d print after\n", min, zero, max);
	printf("count real: %d\n\n", count);

    count = ft_printf("mine: %-20.15d|%-20.15d|%-20.15d print after\n", min, zero, max);
  	printf("count mine: %d\n", count);
    count = printf("real: %-20.15d|%-20.15d|%-20.15d print after\n", min, zero, max);
	printf("count real: %d\n\n", count);
	
    count = ft_printf("mine: %.*u|%.*u print after\n", -15, zero, -15, uns);
	printf("count mine: %d\n", count);
    count = printf("real: %.*u|%.*u print after\n", -15, zero, -15, uns);
	printf("count real: %d\n\n", count);

	count = ft_printf("mine: %015x|%015X|%015x print after\n", min, zero, uns);
	printf("count mine: %d\n", count);
    count = printf("real: %015x|%015x|%015x print after\n", min, zero, uns);
	printf("count real: %d\n\n", count);

    count = ft_printf("mine: %25p|%*p print after\n", ptr_min, 18, ptr_max);
	printf("count mine: %d\n", count);
    count = printf("real: %25p|%*p print after\n", ptr_min, 18, ptr_max);
	printf("count real: %d\n\n", count);

    count = ft_printf("mine: %-10s|%3s print after\n", str, str);
	printf("count mine: %d\n", count);
    count = printf("real: %-10s|%3s print after\n", str, str);
	printf("count real: %d\n\n", count);

    count = ft_printf("mine: %*c print after\n", 10, c);
	printf("count mine: %d\n", count);
    count = printf("real: %*c print after\n", 10, c);
	printf("count real: %d\n\n", count);

    count = ft_printf("mine: %% print after\n");
	printf("count mine: %d\n", count);
    count = printf("real: %% print after\n");
	printf("count real: %d\n\n", count);


//////////////////////////////////////////////////////////////////////

/*
	////////// TESTS FOR INT : d AND i //////////
	count = ft_printf("mine: %d|%i|%d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %d|%i|%d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
	count = ft_printf("mine: %2d|%2i|%*d print after\n", min, zero, 2, max);
    printf("count mine: %d\n", count);
    count = printf("real: %2d|%2i|%*d print after\n", min, zero, 2, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10d|%10d|%10i print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %10d|%10d|%10i print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*i|%*d|%*d print after\n", -10, min, -10, zero, -10, max);
    printf("count mine: %d\n", count);
    count = printf("real: %*i|%*d|%*d print after\n", -10, min, -10, zero, -10, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.20d|%.20i|%.20d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %.20d|%.20i|%.20d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.*i|%.*d|%.*d print after\n", -15, min, -15, zero, -15, max);
    printf("count mine: %d\n", count);
    count = printf("real: %.*i|%.*d|%.*d print after\n", -15, min, -15, zero, -15, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.3d|%5.3i|%5.3d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %5.3d|%5.3i|%5.3d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.20d|%5.20d|%5.20i print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %5.20d|%5.20d|%5.20i print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %25.*d|%25.*d|%25.*i print after\n", 5, min, 5, zero, 5, max);
    printf("count mine: %d\n", count);
    count = printf("real: %25.*d|%25.*d|%25.*i print after\n", 5, min, 5, zero, 5, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.20i|%10.20d|%10.20d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %10.20i|%10.20d|%10.20d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.20d|%*.20i|%*.20d print after\n", -10, min, -10, zero, -10, max);
    printf("count mine: %d\n", count);
    count = printf("real: %*.20d|%*.20i|%*.20d print after\n", -10, min, -10, zero, -10, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.*i|%10.*d|%10.*d print after\n", -20, min, -20, zero, -20, max);
    printf("count mine: %d\n", count);
    count = printf("real: %10.*i|%10.*d|%10.*d print after\n", -20, min, -20, zero, -20, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.*d|%*.*d|%*.*i print after\n", -15, -20, min, -15, -20, zero, -15, -20, max);
    printf("count mine: %d\n", count);
    count = printf("real: %*.*d|%*.*d|%*.*i print after\n", -15, -20, min, -15, -20, zero, -15, -20, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-d|%-d|%-i print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-d|%-d|%-i print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10i|%-10d|%-10d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-10i|%-10d|%-10d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*i|%-*d|%-*d print after\n", -10, min, -10, zero, -10, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-*i|%-*d|%-*d print after\n", -10, min, -10, zero, -10, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.20d|%-.20i|%-.20d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-.20d|%-.20i|%-.20d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.*d|%-.*d|%-.*i print after\n", -15, min, -15, zero, -15, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-.*d|%-.*d|%-.*i print after\n", -15, min, -15, zero, -15, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.3d|%-5.3i|%-5.3d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.3d|%-5.3i|%-5.3d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.20i|%-5.20d|%-5.20d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.20i|%-5.20d|%-5.20d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-25.*d|%-25.*d|%-25.*i print after\n", 5, min, 5, zero, 5, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-25.*d|%-25.*d|%-25.*i print after\n", 5, min, 5, zero, 5, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.20d|%-10.20d|%-10.20i print after\n", min, 5, zero, 5, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.20d|%-10.20d|%-10.20i print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.20d|%-*.20d|%-*.20i print after\n", -10, min, -10, zero, -10, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.20d|%-*.20d|%-*.20i print after\n", -10, min, -10, zero, -10, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.*d|%-10.*i|%-10.*d print after\n", -20, min, -20, zero, -20, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.*d|%-10.*i|%-10.*d print after\n", -20, min, -20, zero, -20, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.*d|%-*.*i|%-*.*d print after\n", -15, -20, min, -15, -20, zero, -15, -20, max);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.*d|%-*.*i|%-*.*d print after\n", -15, -20, min, -15, -20, zero, -15, -20, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0i|%0d|%0d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %0i|%0d|%0d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %08i|%08d|%08d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %08i|%08d|%08d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0*d|%0*i|%0*d print after\n", -8, min, -8, zero, -8, max);
    printf("count mine: %d\n", count);
    count = printf("real: %0*d|%0*i|%0*d print after\n", -8, min, -8, zero, -8, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %020d|%020i|%020d print after\n", min, zero, max);
    printf("count mine: %d\n", count);
    count = printf("real: %020d|%020i|%020d print after\n", min, zero, max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0*d|%0*d|%0*i print after\n", -20, min, -20, zero, -20, max);
    printf("count mine: %d\n", count);
    count = printf("real: %0*d|%0*d|%0*i print after\n", -20, min, -20, zero, -20, max);
    printf("count real: %d\n\n", count);
*/

//////////////////////////////////////////////////////////////////////

/*
	////////// TESTS FOR UNSIGNED INT : u //////////
	count = ft_printf("mine: %u|%u|%u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %u|%u|%u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
	count = ft_printf("mine: %2u|%2u|%*u print after\n", zero, max, 2, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %2u|%2u|%*u print after\n", zero, max, 2, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10u|%10u|%10u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %10u|%10u|%10u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*u|%*u|%*u print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %*u|%*u|%*u print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.20u|%.20u|%.20u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %.20u|%.20u|%.20u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.*u|%.*u|%.*u print after\n", -15, zero, -15, max, -15, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %.*u|%.*u|%.*u print after\n", -15, zero, -15, max, -15, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.3u|%5.3u|%5.3u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %5.3u|%5.3u|%5.3u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.20u|%5.20u|%5.20u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %5.20u|%5.20u|%5.20u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %25.*u|%25.*u|%25.*u print after\n", 5, zero, 5, max, 5, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %25.*u|%25.*u|%25.*u print after\n", 5, zero, 5, max, 5, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.20u|%10.20u|%10.20u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %10.20u|%10.20u|%10.20u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.20u|%*.20u|%*.20u print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %*.20u|%*.20u|%*.20u print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.*u|%10.*u|%10.*u print after\n", -20, zero, -20, max, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %10.*u|%10.*u|%10.*u print after\n", -20, zero, -20, max, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.*u|%*.*u|%*.*u print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %*.*u|%*.*u|%*.*u print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-u|%-u|%-u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-u|%-u|%-u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10u|%-10u|%-10u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-10u|%-10u|%-10u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*u|%-*u|%-*u print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-*u|%-*u|%-*u print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.20u|%-.20u|%-.20u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-.20u|%-.20u|%-.20u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.*u|%-.*u|%-.*u print after\n", -15, zero, -15, max, -15, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-.*u|%-.*u|%-.*u print after\n", -15, zero, -15, max, -15, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.3u|%-5.3u|%-5.3u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.3u|%-5.3u|%-5.3u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.20u|%-5.20u|%-5.20u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.20u|%-5.20u|%-5.20u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-25.*u|%-25.*u|%-25.*u print after\n", 5, zero, 5, max, 5, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-25.*u|%-25.*u|%-25.*u print after\n", 5, zero, 5, max, 5, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.20u|%-10.20u|%-10.20u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.20u|%-10.20u|%-10.20u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.20u|%-*.20u|%-*.20u print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.20u|%-*.20u|%-*.20u print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.*u|%-10.*u|%-10.*u print after\n", -20, zero, -20, max, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.*u|%-10.*u|%-10.*u print after\n", -20, zero, -20, max, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.*u|%-*.*u|%-*.*u print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.*u|%-*.*u|%-*.*u print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0u|%0u|%0u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %0u|%0u|%0u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %08u|%08u|%08u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %08u|%08u|%08u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0*u|%0*u|%0*u print after\n", -8, zero, -8, max, -8, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %0*u|%0*u|%0*u print after\n", -8, zero, -8, max, -8, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %020u|%020u|%020u print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %020u|%020u|%020u print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0*u|%0*u|%0*u print after\n", -20, zero, -20, max, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %0*u|%0*u|%0*u print after\n", -20, zero, -20, max, -20, uns);
    printf("count real: %d\n\n", count);
*/

//////////////////////////////////////////////////////////////////////

/*
	////////// TESTS FOR UNSIGNED INT WRITTEN IN HEXADECIMAL : x AND X //////////
	count = ft_printf("mine: %x|%x|%X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %x|%x|%X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
	count = ft_printf("mine: %2x|%2x|%*X print after\n", zero, max, 2, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %2x|%2x|%*X print after\n", zero, max, 2, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10x|%10x|%10X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %10x|%10x|%10X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*x|%*x|%*X print after\n", -10, zero, -10, uns, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %*x|%*x|%*X print after\n", -10, zero, -10, uns, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.20x|%.20x|%.20X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %.20x|%.20x|%.20X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.*x|%.*x|%.*X print after\n", -15, zero, -15, max, -15, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %.*x|%.*x|%.*X print after\n", -15, zero, -15, max, -15, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.3x|%5.3x|%5.3X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %5.3x|%5.3x|%5.3X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.20x|%5.20x|%5.20X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %5.20x|%5.20x|%5.20X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %25.*x|%25.*x|%25.*X print after\n", 5, zero, 5, max, 5, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %25.*x|%25.*x|%25.*X print after\n", 5, zero, 5, max, 5, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.20x|%10.20x|%10.20X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %10.20x|%10.20x|%10.20X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.20x|%*.20x|%*.20X print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %*.20x|%*.20x|%*.20X print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.*x|%10.*x|%10.*X print after\n", -20, zero, -20, max, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %10.*x|%10.*x|%10.*X print after\n", -20, zero, -20, max, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.*x|%*.*x|%*.*X print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %*.*x|%*.*x|%*.*X print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-x|%-x|%-X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-x|%-x|%-X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10x|%-10x|%-10X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-10x|%-10x|%-10X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*x|%-*x|%-*X print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-*x|%-*x|%-*X print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.20x|%-.20x|%-.20X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-.20x|%-.20x|%-.20X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.*x|%-.*x|%-.*X print after\n", -15, zero, -15, max, -15, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-.*x|%-.*x|%-.*X print after\n", -15, zero, -15, max, -15, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.3x|%-5.3x|%-5.3X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.3x|%-5.3x|%-5.3X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.20x|%-5.20x|%-5.20X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.20x|%-5.20x|%-5.20X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-25.*x|%-25.*x|%-25.*X print after\n", 5, zero, 5, max, 5, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-25.*x|%-25.*x|%-25.*X print after\n", 5, zero, 5, max, 5, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.20x|%-10.20x|%-10.20X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.20x|%-10.20x|%-10.20X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.20x|%-*.20x|%-*.20X print after\n", -10, zero, -10, max, -10, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.20x|%-*.20x|%-*.20X print after\n", -10, zero, -10, max, -10, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.*x|%-10.*x|%-10.*X print after\n", -20, zero, -20, max, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.*x|%-10.*x|%-10.*X print after\n", -20, zero, -20, max, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.*x|%-*.*x|%-*.*X print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.*x|%-*.*x|%-*.*X print after\n", -15, -20, zero, -15, -20, max, -15, -20, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0x|%0x|%0X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %0x|%0x|%0X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %08x|%08x|%08X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %08x|%08x|%08X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0*x|%0*x|%0*X print after\n", -8, zero, -8, max, -8, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %0*x|%0*x|%0*X print after\n", -8, zero, -8, max, -8, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %020x|%020x|%020X print after\n", zero, max, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %020x|%020x|%020X print after\n", zero, max, uns);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %0*x|%0*x|%0*X print after\n", -20, zero, -20, max, -20, uns);
    printf("count mine: %d\n", count);
    count = printf("real: %0*x|%0*x|%0*X print after\n", -20, zero, -20, max, -20, uns);
    printf("count real: %d\n\n", count);
// Note that the int max, 2147483647, is 7FFFFFFF in hexadecimal
// and unsigned int max, 4294967295, is FFFFFFFF.
// There are websites to convert for you if you want to make sure
// I used: https://sebastienguillon.com/test/javascript/convertisseur.html
*/

//////////////////////////////////////////////////////////////////////

/*
	////////// TESTS FOR POINTERS : p //////////
	count = ft_printf("mine: %p|%p print after\n", ptr_min, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %p|%p print after\n", ptr_min, ptr_max);
    printf("count real: %d\n\n", count);
	count = ft_printf("mine: %2p|%2p print after\n", ptr_min, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %2p|%2p print after\n", ptr_min, ptr_max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %20p|%20p print after\n", ptr_min, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %20p|%20p print after\n", ptr_min, ptr_max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*p|%*p print after\n", -20, ptr_min, -20, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %*p|%*p print after\n", -20, ptr_min, -20,ptr_max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-p|%-p print after\n", ptr_min, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %-p|%-p print after\n", ptr_min, ptr_max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-20p|%-20p print after\n", ptr_min, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %-20p|%-20p print after\n", ptr_min, ptr_max);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*p|%-*p print after\n", -20, ptr_min, -20, ptr_max);
    printf("count mine: %d\n", count);
    count = printf("real: %-*p|%-*p print after\n", -20, ptr_min, -20, ptr_max);
    printf("count real: %d\n\n", count);
*/

//////////////////////////////////////////////////////////////////////

/*
	////////// TESTS FOR A CHARACTER : c //////////
	count = ft_printf("mine: %c|%c print after\n", c, c);
    printf("count mine: %d\n", count);
    count = printf("real: %c|%c print after\n", c, c);
    printf("count real: %d\n\n", count);
	count = ft_printf("mine: %2c|%*c print after\n", c, 5, c);
    printf("count mine: %d\n", count);
    count = printf("real: %2c|%*c print after\n", c, 5, c);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10c|%10c print after\n", c, c);
    printf("count mine: %d\n", count);
    count = printf("real: %10c|%10c print after\n", c, c);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*c|%*c print after\n", -6, c, -10, c);
    printf("count mine: %d\n", count);
    count = printf("real: %*c|%*c print after\n", -6, c, -10, c);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-c|%-c print after\n", c, c);
    printf("count mine: %d\n", count);
    count = printf("real: %-c|%-c print after\n", c, c);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10c|%-10c print after\n", c, c);
    printf("count mine: %d\n", count);
    count = printf("real: %-10c|%-10c print after\n", c, c);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*c|%-*c print after\n", -9, c, -10, c);
    printf("count mine: %d\n", count);
    count = printf("real: %-*c|%-*c print after\n", -9, c, -10, c);
    printf("count real: %d\n\n", count);
*/

//////////////////////////////////////////////////////////////////////

/*
	////////// TESTS FOR STRINGS : s //////////
	count = ft_printf("mine: %s|%s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %s|%s print after\n", str, nul);
    printf("count real: %d\n\n", count);
	count = ft_printf("mine: %2s|%*s print after\n", str, 2, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %2s|%*s print after\n", str, 2, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10s|%10s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %10s|%10s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*s|%*s print after\n", -10, str, -10, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %*s|%*s print after\n", -10, str, -10, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.20s|%.20s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %.20s|%.20s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %.*s|%.*s print after\n", -15, str, -15, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %.*s|%.*s print after\n", -15, str, -15, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.3s|%5.3s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %5.3s|%5.3s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %5.20s|%5.20s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %5.20s|%5.20s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %25.*s|%25.*s print after\n", 5, str, 5, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %25.*s|%25.*s print after\n", 5, str, 5, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.20s|%10.20s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %10.20s|%10.20s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.20s|%*.20s print after\n", -10, str, -10, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %*.20s|%*.20s print after\n", -10, str, -10, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %10.*s|%10.*s print after\n", -20, str, -20, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %10.*s|%10.*s print after\n", -20, str, -20, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %*.*s|%*.*s print after\n", -15, -20, str, -15, -20, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %*.*s|%*.*s print after\n", -15, -20, str, -15, -20, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-s|%-s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-s|%-s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10s|%-10s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-10s|%-10s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*s|%-*s print after\n", -10, str, -10, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-*s|%-*s print after\n", -10, str, -10, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.20s|%-.20s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-.20s|%-.20s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-.*s|%-.*s print after\n", -15, str, -15, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-.*s|%-.*s print after\n", -15, str, -15, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.3s|%-5.3s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.3s|%-5.3s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-5.20s|%-5.20s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-5.20s|%-5.20s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-25.*s|%-25.*s print after\n", 5, str, 5, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-25.*s|%-25.*s print after\n", 5, str, 5, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.20s|%-10.20s print after\n", str, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.20s|%-10.20s print after\n", str, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.20s|%-*.20s print after\n", -10, str, -10, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.20s|%-*.20s print after\n", -10, str, -10, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-10.*s|%-10.*s print after\n", -20, str, -20, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-10.*s|%-10.*s print after\n", -20, str, -20, nul);
    printf("count real: %d\n\n", count);
    count = ft_printf("mine: %-*.*s|%-*.*s print after\n", -15, -20, str, -15, -20, nul);
    printf("count mine: %d\n", count);
    count = printf("real: %-*.*s|%-*.*s print after\n", -15, -20, str, -15, -20, nul);
    printf("count real: %d\n\n", count);
*/

	(void)min;		// Just in case you don't test all variables at once, I'm "voiding" it afterwards so you don't get an error
	(void)zero;
	(void)max;
	(void)uns;
	(void)ptr_min;
	(void)ptr_max;
	(void)c;
	(void)str;
	(void)nul;
}
