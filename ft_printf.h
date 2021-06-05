/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:40:57 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/31 13:45:39 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_percent(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point(const char *format, unsigned int i, \
va_list param, unsigned int *count);
void			ft_putchar(char c, unsigned int *count);
void			ft_putstr(char *str, unsigned int *count);
void			ft_putnbr(long long nb, unsigned int *count);
int				ft_strlen(char *s);
void			ft_to_hexa(unsigned long long nb, char *base, \
unsigned int *count);
int				ft_calcul_width(const char *format, unsigned int i, \
va_list param, unsigned int *ptr_i);
int				ft_get_size(long long nb);
int				ft_get_size_hexa(long long unsigned nb);
void			ft_print_spaces(int width, int precision, \
int size, unsigned int *count);
void			ft_print_zeros(int width, int size, unsigned int *count);
long			ft_nb_negative(int nb);
int				ft_precision_point(const char *f, unsigned int i, \
va_list param, unsigned int *ptr_i);
void			ft_print_spaces_point_int(long long nb, int precision, \
int width, unsigned int *count);
void			ft_print_spaces_point_x(long long nb, int precision, \
int width, unsigned int *count);
void			ft_print_spaces_point_p(long long nb, int precision, \
int width, unsigned int *count);
int				ft_point_zero_int(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_zero_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_zero_x(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_zero_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_zero_p(const char *format, unsigned int i, \
va_list param, unsigned int *count);
void			ft_print_zeros_z_int(int precision, int nb, int width, \
unsigned int *count);
int				ft_point_zero_c(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_zero_s(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_zero(const char *format, unsigned int i, \
va_list param, unsigned int *count);
void			ft_print_d_letters(int precision, char *str, \
unsigned int *count);
void			ft_print_spaces_d_int(int nb, int precision, \
int width, unsigned int *count);
int				ft_point_dash_int(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash_x(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash_p(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash_c(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash_s(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_dash(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_int(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_x(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_p(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_c(const char *format, unsigned int i, \
va_list param, unsigned int *count);
void			ft_print_spaces_point_s(int precision, char *str, \
int width, unsigned int *count);
int				ft_point_s(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_point_specifier(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_int(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_x(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_p(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_c(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero_s(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_zero(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_int(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_x(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_p(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_c(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash_s(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_dash(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_int(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_uns(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_x(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_xmaj(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_p(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_c(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_s(const char *format, unsigned int i, \
va_list param, unsigned int *count);
int				ft_no_point_specifier(const char *format, \
unsigned int i, va_list param, unsigned int *count);
unsigned int	ft_go_ahead(const char *format, \
unsigned int i, char c, char d);

#endif
