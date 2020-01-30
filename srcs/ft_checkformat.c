/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checkformat.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 16:45:48 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 11:18:52 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"
#include <unistd.h>

/*
** flag_bool is used to redo the if statement when it returns to start
** again.
*/

static int	ft_checkforflags(int i, const char *format, t_flag *flags, \
va_list argp)
{
	if (format[i] == '+' || format[i] == '#')
	{
		flags->plus_flag = (format[i] == '+') ? 1 : 0;
		flags->flag_bool = (format[i] == '+' || \
		format[i] == '#') ? 1 : 0;
		flags->hash_flag = (format[i] == '#') ? 1 : 0;
		flags->flag_bool = 1;
	}
	if (format[i] == '-' || format[i] == '0')
		i = check_minus_zero(i, format, flags, argp);
	else if (ft_isdigit(format[i]) || format[i] == '*')
		i = check_minwidth_wildcard(i, format, flags, argp);
	if (format[i] == '.')
		i = check_for_prec(i, format, flags, argp);
	if (format[i] == 'c' || format[i] == 's')
		flags->data_type = (format[i] == 'c') ? 1 : 2;
	else if (format[i] == 'p' || format[i] == 'i' || format[i] == 'd')
		flags->data_type = (format[i] == 'p') ? 3 : 4;
	else if (format[i] == 'u' || format[i] == 'x')
		flags->data_type = (format[i] == 'u') ? 5 : 6;
	else if (format[i] == 'X' || format[i] == '%')
		flags->data_type = (format[i] == 'X') ? 7 : 8;
	else if (ft_isalpha(format[i]))
		flags->data_type = -1;
	return (i);
}

static void	ft_checkformat_two(t_flag *flags, va_list argp)
{
	flags->flag_type = (flags->flag_type > 0 && \
	flags->width_amount == 0) ? 0 : flags->flag_type;
	if (flags->data_type > 0 && flags->flag_type == 0 \
	&& flags->prec_bool == 0)
		ft_printing_noflags(flags, argp);
	else if ((flags->data_type > 0 && flags->flag_type > 0) || \
	(flags->data_type > 0 && flags->prec_bool == 1))
		ft_printing_with_flags(flags, argp);
	else if (flags->data_type == 0)
		flags->flag_bool = 1;
	return ;
}

void		ft_checkformat(const char *format, t_flag *flags, int i, \
va_list argp)
{
	while (format[i] != '\0' && flags->error != -1)
	{
		if ((format[i] == '%' || flags->flag_bool == 1) && flags->error != -1)
		{
			flags->flag_bool = 0;
			i++;
			flags->width_count = i;
			if (format[flags->width_count] == ' ')
				i = check_spaces(i, 1, format, flags);
			i = ft_checkforflags(i, format, flags, argp);
			if (flags->flag_bool == 1)
				continue;
			ft_checkformat_two(flags, argp);
			if (flags->flag_bool == 1)
				continue;
			if (flags->error == -1)
				break ;
		}
		else
			flags->total_print += ft_putchar_fd_return(format[i], 1, flags);
		i++;
	}
	va_end(argp);
}
