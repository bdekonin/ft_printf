/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_print_pointer.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 16:31:59 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 11:15:54 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

/*
** First i will print out the 0x. I use putnbr_neg because i use the same,
** function also for the hashflag with x & X, so otherwise it will
** just print out the rest of the steps.
*/

static void	ft_flags_one(char *s, int fd, t_flag *flags)
{
	if (flags->putnbr_neg == 1 && flags->error != -1)
		flags->total_print += ft_putstr_fd_return(flags->zero_x, 1, flags);
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	flags->total_print += ft_putstr_fd_return(s, fd, flags);
	while (flags->index_i < (flags->width_amount - (int)ft_strlen(s)) && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
}

static void	ft_flags_two(char *s, int fd, t_flag *flags)
{
	if (flags->putnbr_neg == 1 && flags->prec_bool == 0 && \
	flags->error != -1)
		flags->total_print += ft_putstr_fd_return(flags->zero_x, 1, flags);
	while (flags->index_i < (flags->width_amount - (int)ft_strlen(s)) && \
	flags->error != -1)
	{
		if (flags->prec_bool == 0)
			flags->total_print += ft_putchar_fd_return(flags->zero, \
			fd, flags);
		else
			flags->total_print += ft_putchar_fd_return(flags->space, \
			fd, flags);
		flags->index_i++;
	}
	if (flags->putnbr_neg == 1 && flags->prec_bool != 0 && flags->error != -1)
		flags->total_print += ft_putstr_fd_return(flags->zero_x, 1, flags);
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
}

static void	ft_flags_three(char *s, int fd, t_flag *flags)
{
	while (flags->index_i < (flags->width_amount - (int)ft_strlen(s)) \
	&& flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
		flags->index_i++;
	}
	if (flags->putnbr_neg == 1 && flags->error != -1)
	{
		flags->total_print += ft_putstr_fd_return(flags->zero_x, 1, flags);
		if (ft_strncmp(s, "0x", 100) == 0)
			flags->putnbr_neg = 3;
	}
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->putnbr_neg != 3 && flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
}

static void	ft_flags_else(char *s, int fd, t_flag *flags)
{
	if (flags->putnbr_neg == 1 && flags->error != -1)
		flags->total_print += ft_putstr_fd_return(flags->zero_x, 1, flags);
	while (flags->index_j < flags->precision && flags->prec_bool == 1 && \
	flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
		flags->index_j++;
	}
	if (flags->error != -1)
		flags->total_print += ft_putstr_fd_return(s, fd, flags);
}

/*
** First I use ternery operators for setting everything up.
** then I check if the awns is 0, if so i print out 0x0
** and also check for the space flag. and print out out a space which
** i will remove from the min width. Then i just go through multiple flags.
** e.g if the flag is number 1 and my program hasnt given me an error yet
** it will go to the first if statement. The explanation will be at the top.
** then I will just return out of the function.
*/

void		ft_putnbr_print_pointer(char *s, int fd, t_flag *flags)
{
	flags->width_count = flags->precision;
	flags->prec_bool = (flags->precision > 0) ? 1 : 0;
	flags->precision = (flags->precision >= (int)ft_strlen(s)) ? \
	(flags->precision - (int)ft_strlen(s)) : 0;
	flags->width_amount = flags->width_amount - flags->precision - 1;
	flags->width_amount -= (flags->putnbr_neg == 1) ? 1 : 0;
	if (flags->putnbr_neg == 3 && flags->error != -1)
	{
		flags->total_print += ft_putstr_fd_return("0x0", 1, flags);
		return ;
	}
	if (flags->space_count > 0 && flags->putnbr_neg == 0 && flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(' ', fd, flags);
		flags->width_amount -= 1;
	}
	if (flags->flag_type == 1 && flags->error != -1)
		ft_flags_one(s, fd, flags);
	else if (flags->flag_type == 2 && flags->error != -1)
		ft_flags_two(s, fd, flags);
	else if (flags->flag_type == 3 && flags->error != -1)
		ft_flags_three(s, fd, flags);
	else if (flags->error != -1)
		ft_flags_else(s, fd, flags);
	return ;
}
