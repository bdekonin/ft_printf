/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_flags_print.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 07:23:29 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 11:48:41 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_print_flag_three(char *s, int fd, t_flag *flags)
{
	while ((flags->index_i < (flags->width_amount - (int)ft_strlen(s))) \
	&& flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	flags->total_print += ft_putstr_fd_return(s, fd, flags);
}

static void		ft_print_flag_two(char *s, int fd, t_flag *flags)
{
	while ((flags->index_i < (flags->width_amount - (int)ft_strlen(s))) && \
	flags->error != -1)
	{
		if (((flags->prec_bool == 0 && flags->data_type != 4 && \
		flags->flag_type != 2) || flags->hash_flag == -1) && flags->error != -1)
			flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		else
			flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
}

static void		ft_print_flag_one(char *s, int fd, t_flag *flags)
{
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		if (flags->prec_bool == 1 && flags->error != -1)
			flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		else
			flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_j++;
	}
	while (flags->index_j < flags->precision && flags->prec_bool == 0 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, 1, flags);
	while ((flags->index_i < (flags->width_amount - (int)ft_strlen(s))) && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
}

static void		ft_putnbr_flags_print_five(char *s, int fd, t_flag *flags)
{
	if (flags->flag_type == 1 && flags->error != -1)
		ft_print_flag_one(s, fd, flags);
	else if (flags->flag_type == 2 && flags->error != -1)
		ft_print_flag_two(s, fd, flags);
	else if (flags->flag_type == 3 && flags->error != -1)
		ft_print_flag_three(s, fd, flags);
	else if (flags->error != -1)
	{
		while (((flags->index_j < flags->precision \
		&& flags->prec_bool == 1) || (flags->hash_flag == -1 && \
		(flags->data_type != 6 && flags->data_type != 7))) && \
		flags->error != -1)
		{
			flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
			flags->index_j++;
		}
		if (flags->error != -1)
			flags->total_print += ft_putstr_fd_return(s, fd, flags);
	}
	return ;
}

/*
** I firstly malloc protact at the top, and if it fails it will.
** eventually fall back, to the main function which then returns -1;
**	 s[0] = (s[0] == '0' && s[1] != 'x') ? '0' : s[0];
*/

void			ft_putnbr_flags_print(char *s, int fd, t_flag *flags)
{
	int length;

	if (checkerror(s, s, flags, 0) == -1)
		return ;
	length = (int)ft_strlen(s);
	flags->hash_flag = flags->precision;
	s[0] = (flags->flag_type > 0 && flags->precision == 0 && s[0] == '0') ? \
	'\0' : s[0];
	flags->precision *= (flags->precision < -1) ? -1 : 1;
	flags->width_count = flags->precision;
	flags->prec_bool = (flags->precision > 0) ? 1 : 0;
	flags->precision = (flags->precision >= length) ? \
	(flags->precision - length) : 0;
	flags->width_amount = flags->width_amount - flags->precision;
	if (flags->space_count > 0 && flags->putnbr_neg == 0 && flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(' ', fd, flags);
		flags->width_amount -= 1;
	}
	if (flags->error != -1)
		ft_putnbr_flags_print_five(s, fd, flags);
	if (flags->data_type != 4 && flags->data_type != 5)
		free(s);
	return ;
}
