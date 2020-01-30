/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 12:15:01 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int		ft_putnbr_flags_three(long long n, int fd, char *str, \
t_flag *flags)
{
	if (flags->precision == 0 & n == 0 && flags->width_amount == 0 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return('+', 1, flags);
		return (1);
	}
	flags->putnbr_neg = 1;
	flags->minus = '+';
	str = ft_itoa_long(n, flags);
	if (checkerror(str, str, flags, 0) == -1)
		return (-1);
	ft_putnbr_flags_print_negative(str, fd, flags);
	free(str);
	return (0);
}

/*
** USED IF N IS BELOW ZERO DIT NAGAAN NOGMAALS
*/

static int		ft_below_zero(long long n, int fd, char *str, t_flag *flags)
{
	n = n * -1;
	flags->putnbr_neg = 1;
	str = (n != 2147483648) ? ft_itoa_long(n, flags) : \
	ft_strdup("2147483648");
	if (checkerror(str, str, flags, 0) == -1)
		return (-1);
	ft_putnbr_flags_print_negative(str, fd, flags);
	free(str);
	return (0);
}

static int		ft_putnbr_flags_two(long long n, int fd, char *str, \
t_flag *flags)
{
	if (n < 0 && flags->error != -1)
	{
		if (ft_below_zero(n, fd, str, flags) == -1)
			return (-1);
	}
	else if (n == 0 && flags->prec_bool == 1 && flags->width_amount == \
	0 && flags->precision == 0 && flags->error != -1)
	{
		if (flags->space_count != 0)
			flags->total_print += ft_putchar_fd_return(' ', 1, flags);
		return (1);
	}
	else if (flags->error != -1)
	{
		str = ft_itoa_long(n, flags);
		if (checkerror(str, str, flags, 0) == -1)
			return (-1);
		ft_putnbr_flags_print(str, fd, flags);
		free(str);
	}
	return (0);
}

static int		ft_putnbr_flags_one(long long n, int fd, char \
*str, t_flag *flags)
{
	if (flags->data_type == 5 && (int)n < 0 && flags->error != -1)
	{
		flags->width_count = (int)n * -1;
		n = 4294967295;
		n -= (long long)flags->width_count - 1;
		str = ft_itoa_long(n, flags);
		if (checkerror(str, str, flags, 0) == -1)
			return (-1);
		ft_putnbr_flags_print(str, fd, flags);
		free(str);
	}
	else if (flags->plus_flag == 1 && flags->flag_type == \
	0 && n > -1 && flags->prec_bool == 0 && flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return('+', 1, flags);
		flags->index_j++;
		if (flags->error == -1)
			return (0);
		flags->total_print += ft_putnbr_fd_return(n, 1, flags);
		return (0);
	}
	return (0);
}

int				ft_putnbr_flags(long long n, int fd, t_flag *flags)
{
	char	*str;
	int		yes_or_no;

	str = "";
	n = (flags->data_type == 4 && n == -2147483648) ? -2147483648 : n;
	if ((flags->data_type == 5 && (int)n < 0 \
	&& flags->error != -1) || (flags->plus_flag == 1 && flags->flag_type \
	== 0 && n > -1 && flags->prec_bool == 0 && flags->error != -1))
		ft_putnbr_flags_one(n, fd, str, flags);
	else if (flags->plus_flag == 1 && (flags->flag_type > \
0 || flags->precision > -1) && n > -1 && flags->error != -1)
	{
		yes_or_no = ft_putnbr_flags_three(n, fd, str, flags);
		if (yes_or_no == 1)
			return (0);
	}
	else if (flags->error != -1)
	{
		yes_or_no = ft_putnbr_flags_two(n, fd, str, flags);
		if (yes_or_no == 1)
			return (0);
	}
	return (0);
}
