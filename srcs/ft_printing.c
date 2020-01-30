/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 14:51:13 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_printing_noflags(t_flag *flags, va_list argp)
{
	if (flags->data_type == 4 && flags->plus_flag == 1)
		flags->total_print += ft_putnbr_flags(va_arg(argp, int), 1, flags);
	else if (flags->data_type == 1)
		flags->total_print += ft_putchar_fd_return(va_arg(argp, int), 1, flags);
	else if (flags->data_type == 2)
		flags->total_print += \
		ft_putstr_fd_return(va_arg(argp, char*), 1, flags);
	else if (flags->data_type == 3)
		flags->total_print += \
		ft_hex_convert_pointer(va_arg(argp, unsigned long long), 87, flags);
	else if (flags->data_type == 4)
		flags->total_print += ft_putnbr_fd_return(va_arg(argp, int), 1, flags);
	else if (flags->data_type == 5)
		flags->total_print += \
		ft_putnbr_fd_return_unsigned(va_arg(argp, unsigned int), 1, flags);
	else if (flags->data_type == 6)
		flags->total_print += ft_hex_convert(va_arg(argp, unsigned int), \
		87, 0, flags);
	else if (flags->data_type == 7)
		flags->total_print += ft_hex_convert(va_arg(argp, unsigned int), \
		55, 0, flags);
	else if (flags->data_type == 8)
		flags->total_print += ft_putchar_fd_return('%', 1, flags);
	flags = ft_structset(flags);
	return (1);
}

int		ft_printing_with_flags(t_flag *flags, va_list argp)
{
	if (flags->data_type == 4 && flags->plus_flag == 1)
		flags->total_print += ft_putnbr_flags(va_arg(argp, int), 1, flags);
	else if (flags->data_type == 1)
		ft_putchar_flags(va_arg(argp, int), 1, flags);
	else if (flags->data_type == 2)
		ft_putstr_flags(va_arg(argp, char*), 1, flags);
	else if (flags->data_type == 3)
		flags->total_print += \
		ft_hex_convert_pointer(va_arg(argp, long long), 87, flags);
	else if (flags->data_type == 4)
		flags->total_print += ft_putnbr_flags(va_arg(argp, int), 1, flags);
	else if (flags->data_type == 5)
		flags->total_print += \
		ft_putnbr_flags(va_arg(argp, unsigned int), 1, flags);
	else if (flags->data_type == 6)
		flags->total_print += ft_hex_convert(va_arg(argp, int), 87, 2, flags);
	else if (flags->data_type == 7)
		flags->total_print += ft_hex_convert(va_arg(argp, int), 55, 2, flags);
	else if (flags->data_type == 8)
		ft_putchar_flags('%', 1, flags);
	flags = ft_structset(flags);
	return (1);
}

/*
** this function is used by different flags, so i used
** flag_bool to identify different while loops.
** 0 == '-' || '0'
*/

int		ft_checkforflags(int i, const char *format, int flag_bool, \
t_flag *flags)
{
	while (flag_bool == 0 && ft_isalpha(format[i]))
		i++;
	while (flag_bool == 1 && ft_isalpha(format[i]) == 0 && format[i] != '%')
	{
		i++;
		if (format[i] == '.')
			break ;
	}
	if (flag_bool == 3 && (format[flags->width_count - 1] == '-' || \
	format[flags->width_count - 1] == '0') && format[flags->width_count] == '*')
		return (-8);
	if (flag_bool == 4 && (format[i + 1] == '-' || format[i + 1] == '0' || \
	format[i + 1] == '+' || format[i + 1] == ' '))
		return (-8);
	return (i);
}

int		ft_intlen(long long n, int base)
{
	int count;

	count = 1;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int		ft_intlen_unsigned(unsigned long long n, int base)
{
	int count;

	count = 1;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
