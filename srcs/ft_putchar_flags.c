/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:07:58 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <unistd.h>

static void	ft_putchar_flags_two(char c, int fd, t_flag *flags, int i)
{
	if (flags->flag_type == 3 && flags->error != -1)
	{
		while (i < (flags->width_amount - 1) && flags->error != -1)
		{
			flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
			i++;
		}
		if (flags->error != -1)
			flags->total_print += ft_putchar_fd_return(c, fd, flags);
	}
	else if (flags->precision == 0 && flags->prec_bool == 1 && \
	flags->flag_type == 0 && flags->error != -1)
		flags->total_print += ft_putchar_fd_return(c, fd, flags);
	else if (flags->precision > -1 && flags->error != -1)
		flags->total_print += ft_putchar_fd_return(c, fd, flags);
	return ;
}

int			ft_putchar_flags(char c, int fd, t_flag *flags)
{
	int i;

	i = 0;
	if (flags->flag_type == 1 && flags->error != -1)
	{
		flags->total_print += ft_putchar_fd_return(c, fd, flags);
		while (i < (flags->width_amount - 1) && flags->error != -1)
		{
			flags->total_print += ft_putchar_fd_return(flags->space, fd, flags);
			i++;
		}
	}
	else if (flags->flag_type == 2 && flags->error != -1)
	{
		while (i < (flags->width_amount - 1) && flags->error != -1)
		{
			flags->total_print += ft_putchar_fd_return(flags->zero, fd, flags);
			i++;
		}
		if (flags->error != -1)
			flags->total_print += ft_putchar_fd_return(c, fd, flags);
	}
	else if (flags->error != -1)
		ft_putchar_flags_two(c, fd, flags, i);
	return (0);
}
