/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 16:28:36 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 11:54:19 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_putstr_flags_four(char *s, int fd, t_flag *flags)
{
	if ((size_t)flags->precision < ft_strlen(s) && flags->error != -1)
		while (flags->index_j != flags->precision && flags->error != -1)
		{
			ft_putchar_fd_return(s[flags->index_j], fd, flags);
			flags->index_j++;
		}
	else if (flags->error != -1)
	{
		ft_putstr_fd_return(s, 1, flags);
		flags->total_print = flags->total_print + (int)ft_strlen(s);
	}
}

static void		ft_putstr_flags_three(char *s, int fd, t_flag *flags)
{
	if (flags->flag_type == 3 && flags->error != -1)
	{
		flags->precision = ((size_t)flags->precision <= ft_strlen(s)) ? \
		flags->precision : ft_strlen(s);
		while (flags->index_i < (flags->width_amount - flags->precision) && \
		flags->error != -1)
		{
			ft_putchar_fd_return(flags->space, 1, flags);
			flags->index_i++;
		}
		while (((s[flags->index_j] && flags->index_j != flags->precision) || \
		(s[flags->index_j] && flags->prec_bool == 0)) && flags->error != -1)
		{
			ft_putchar_fd_return(s[flags->index_j], fd, flags);
			flags->index_j++;
		}
	}
	else if (flags->error != -1)
		ft_putstr_flags_four(s, fd, flags);
	return ;
}

static void		ft_putstr_flags_two(char *s, int fd, t_flag *flags)
{
	if (flags->flag_type == 2 && flags->error != -1)
	{
		flags->precision = ((size_t)flags->precision <= ft_strlen(s)) ? \
		flags->precision : ft_strlen(s);
		while (flags->index_i < (flags->width_amount - flags->precision) \
		&& flags->error != -1)
		{
			ft_putchar_fd_return(flags->zero, 1, flags);
			flags->index_i++;
		}
		while (((s[flags->index_j] && flags->index_j != flags->precision) \
		|| (s[flags->index_j] && flags->prec_bool == 0)) && flags->error != -1)
		{
			ft_putchar_fd_return(s[flags->index_j], fd, flags);
			flags->index_j++;
		}
	}
	else if (flags->error != -1)
		ft_putstr_flags_three(s, fd, flags);
	return ;
}

void			ft_putstr_flags(char *s, int fd, t_flag *flags)
{
	s = (s == NULL) ? "(null)" : s;
	if (flags->flag_type == 1 && flags->error != -1)
	{
		while (((s[flags->index_j] && flags->index_j != flags->precision) \
		|| (s[flags->index_j] && flags->prec_bool == 0)) && flags->error != -1)
		{
			ft_putchar_fd_return(s[flags->index_j], fd, flags);
			flags->index_j++;
		}
		flags->precision = ((size_t)flags->precision <= ft_strlen(s)) \
		? flags->precision : ft_strlen(s);
		while (flags->index_i < (flags->width_amount - flags->precision) \
		&& flags->error != -1)
		{
			ft_putchar_fd_return(flags->space, 1, flags);
			flags->index_i++;
		}
	}
	else if (flags->error != -1)
		ft_putstr_flags_two(s, fd, flags);
	flags->total_print += flags->index_i + flags->index_j;
	return ;
}
