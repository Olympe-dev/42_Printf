/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_letters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:16:30 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/31 12:16:31 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_go_ahead(const char *format, unsigned int i, char c, char d)
{
	while (format[i] == c || format[i] == d)
		i++;
	return (i);
}

int	ft_precision_point(const char *f, unsigned int i, \
		va_list param, unsigned int *ptr_i)
{
	int	precision;

	precision = 0;
	if (f[i] == '.' && ((f[i + 1] >= '0' && f[i + 1] <= '9')
			|| f[i + 1] == '*'))
	{
		i++;
		precision = ft_calcul_width(f, i, param, &i);
	}
	else if (f[i] == '.' && !((f[i + 1] >= '0' && f[i + 1] <= '9')
			|| f[i + 1] == '*'))
		i++;
	*ptr_i = i;
	return (precision);
}
