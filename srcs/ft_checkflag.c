/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checkflag.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:58 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

/*
** bool == 0 & 1. It keeps looping if the number is a digit, if true.
** it stores the number into the struct variable given.
** If the bool == 2, if it finds multiple . It saves that location.
** it also counts up how many more wildcard is sees for if the format is .*.*
** then is returns the i, so the function that called it can continue from
** that point on.
*/

static int		flags_gather(const char *format, int i, t_flag *flags, int bool)
{
	while (bool == 0 && ft_isdigit(format[i]))
	{
		flags->width_amount *= 10;
		flags->width_amount += format[i] - 48;
		i++;
	}
	while (bool == 1 && ft_isdigit(format[i]))
	{
		flags->precision *= 10;
		flags->precision += format[i] - 48;
		i++;
	}
	while (bool == 2 && !ft_isalpha(format[i]) && format[i] != '%')
	{
		if (format[i] == '.')
		{
			flags->precision = 0;
			flags->prec_bool = 1;
			flags->prec_point = i;
		}
		if (format[i] == '*')
			flags->arg_count++;
		i++;
	}
	return (i);
}

int				check_minus_zero(int i, const char *format, \
t_flag *flags, va_list argp)
{
	flags->flag_type = (format[i] == '-') ? 1 : 2;
	i++;
	check_spaces(i, 0, format, flags);
	while (format[i] == '-' || format[i] == '0' || format[i] == ' ')
	{
		if (format[i] == '-')
			flags->flag_type = 1;
		i++;
	}
	if (format[i] == '*')
	{
		flags->width_amount = va_arg(argp, int);
		if (flags->width_amount < 0)
		{
			flags->width_amount *= -1;
			flags->flag_type = 1;
		}
		i++;
	}
	i = flags_gather(format, i, flags, 0);
	return (i);
}

/*
** I set the flag_type on 3 which is the minimum width
** then i count the spaces to use for the space flag.
** if i find a * then i will va_arg that it into width amount.
** if it is < 0. I will change the flag_type and make it positive.
** then i will gather the numbers and put it into width amount.
** flags_gather returns an number. and from that point i will,
** continue counting. then return i again.
*/

int				check_minwidth_wildcard(int i, const char *format, \
t_flag *flags, va_list argp)
{
	flags->flag_type = 3;
	if (format[i + 1] == ' ')
		flags->space_count++;
	if (format[i] == '*')
	{
		flags->width_amount = va_arg(argp, int);
		if (flags->width_amount < 0)
		{
			flags->width_amount *= -1;
			flags->flag_type = 1;
		}
		i++;
	}
	i = flags_gather(format, i, flags, 0);
	return (i);
}

/*
** First i set i on the last . flags_gather could find.
** my program also va args the amount of times it could find a *
** used for .*.*.*.*
** once it finally finds the last * it va args that number.
** if the nuumber is below 0, I turn precision off.
** i also check for if it finds a -. if so it does the function.
*/

int				check_for_prec(int i, const char *format, \
t_flag *flags, va_list argp)
{
	i = flags_gather(format, i, flags, 2);
	i = flags->prec_point;
	i++;
	while (flags->star_point < flags->arg_count)
	{
		flags->flag_continue = va_arg(argp, int);
		flags->star_point++;
	}
	if (format[i] == '*')
	{
		flags->precision = va_arg(argp, int);
		if (flags->precision < 0)
		{
			flags->star_point = flags->precision;
			flags->precision = -1;
			flags->prec_bool = 0;
		}
		i++;
	}
	if (format[i] == '-')
		i = check_minus_zero(i, format, flags, argp);
	i = flags_gather(format, i, flags, 1);
	return (i);
}

/*
** I have 2 bools. number 0 is
** number 1 is used at the beginning of checkformat. and looks
** how many spaces there are and counts them up.
** and then returns i from that location.
*/

int				check_spaces(int i, int bool, const char *format, \
t_flag *flags)
{
	if (bool == 0)
	{
		while (bool == 0 && format[i] != 'c' && format[i] != 's' && \
		format[i] != 'i' \
		&& format[i] != 'd' && format[i] != 'u' && format[i] != 'x' && \
		format[i] != 'X' && format[i] != 'p' && format[i] != '.' \
		&& format[i] != '%')
		{
			if (format[i] == ' ')
				flags->space_count++;
			i++;
		}
		return (0);
	}
	else if (bool == 1)
	{
		while (bool == 1 && format[flags->width_count] == ' ')
		{
			flags->space_count++;
			flags->width_count++;
			i++;
		}
		return (i);
	}
	return (0);
}
