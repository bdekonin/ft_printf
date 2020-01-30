/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_flags_negative.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 07:22:39 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_putnbr_flag_one(char *s, int fd, t_flag *flags)
{
	if (flags->putnbr_neg == 1 && flags->error != -1)
		flags->total_print += ft_putchar_fd_return(flags->minus, fd, \
		flags);
	while (flags->index_j < flags->precision && flags->prec_bool == 1 \
	&& flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
	while ((flags->index_i < (flags->width_amount - (int)ft_strlen(s))) \
	&& flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
	return ;
}

static void		ft_putnbr_flag_two(char *s, int fd, t_flag *flags)
{
	if (flags->putnbr_neg == 1 && flags->prec_bool == 0 && \
	flags->hash_flag == -1 && flags->error != -1)
		flags->total_print += ft_putchar_fd_return(flags->minus, fd, flags);
	while ((flags->index_i < (flags->width_amount - (int)ft_strlen(s))) \
	&& flags->error != -1)
	{
		if (flags->prec_bool == 0 && flags->hash_flag == -1 && \
		flags->error != -1)
			flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		else if (flags->error != -1)
			flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
	if (((flags->putnbr_neg == 1 && flags->prec_bool != 0) || \
	flags->hash_flag != -1) && flags->error != -1)
		flags->total_print += ft_putchar_fd_return(flags->minus, fd, flags);
	while (flags->index_j < flags->precision && flags->prec_bool \
	== 1 && flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
	return ;
}

static void		ft_putnbr_flag_three(char *s, int fd, t_flag *flags)
{
	if (flags->flag_type == 2 && flags->error != -1)
		ft_putnbr_flag_two(s, fd, flags);
	else
	{
		while ((flags->index_i < (flags->width_amount - (int)ft_strlen(s))) \
		&& flags->error != -1)
		{
			flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
			flags->index_i++;
		}
		if (flags->putnbr_neg == 1 && flags->error != -1)
			flags->total_print += ft_putchar_fd_return(flags->minus, fd, flags);
		while (flags->index_j < flags->precision && flags->prec_bool \
		== 1 && flags->error != -1)
		{
			flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
			flags->index_j++;
		}
		if (flags->error != -1)
			flags->total_print += ft_putstr_fd_return(s, fd, flags);
	}
	return ;
}

static void		ft_putnbr_neg_two(char *s, int fd, t_flag *flags)
{
	if (flags->putnbr_neg == 1 && flags->error != -1)
		flags->total_print += ft_putchar_fd_return(flags->minus, fd, flags);
	while (flags->index_j < flags->precision && flags->prec_bool == 1
	&& flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
	return ;
}

void			ft_putnbr_flags_print_negative(char *s, int fd, t_flag *flags)
{
	int length;

	s[0] = (flags->flag_type > 0 && flags->precision == 0 \
	&& flags->putnbr_neg != 1) ? '\0' : s[0];
	length = (int)ft_strlen(s);
	flags->hash_flag = flags->precision;
	flags->width_count = flags->precision;
	flags->prec_bool = (flags->precision > 0) ? 1 : 0;
	flags->precision = (flags->precision >= length) ? \
	(flags->precision - length) : 0;
	flags->width_amount = flags->width_amount - flags->precision - 1;
	if (flags->space_count > 0 && flags->putnbr_neg == 0)
	{
		flags->total_print += ft_putchar_fd_return(' ', fd, flags);
		flags->width_amount -= 1;
	}
	if (flags->flag_type == 1 && flags->error != -1)
		ft_putnbr_flag_one(s, fd, flags);
	else if ((flags->flag_type == 3 && flags->error != -1) || \
	(flags->flag_type == 2 && flags->error != -1))
		ft_putnbr_flag_three(s, fd, flags);
	else if (flags->error != -1)
		ft_putnbr_neg_two(s, fd, flags);
	return ;
}
