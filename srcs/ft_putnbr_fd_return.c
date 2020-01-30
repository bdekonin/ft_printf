/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd_return.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 06:49:13 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_putnbr_fd_return_three(t_flag *flags)
{
	flags->total_print += ft_putchar_fd_return(flags->space, 1, flags);
	flags->space_count--;
	flags->index_j++;
}

static void		ft_putnbr_fd_return_two(t_flag *flags)
{
	flags->total_print++;
	flags->index_i++;
	flags->index_j++;
}

int				ft_putnbr_fd_return(int n, int fd, t_flag *flags)
{
	if (flags->error == -1)
		return (0);
	if (flags->index_i == 0 && n < 0)
		ft_putnbr_fd_return_two(flags);
	if (flags->space_count > 0 && flags->index_j == 0)
		ft_putnbr_fd_return_three(flags);
	if (n == 0)
		return (ft_putchar_fd_return('0', 1, flags));
	else if (n == -2147483648)
		return (ft_putstr_fd_return("-2147483648", fd, flags) - 1);
	else if (n < 0)
	{
		ft_putchar_fd_return('-', fd, flags);
		n = n * -1;
		ft_putnbr_fd_return(n, fd, flags);
	}
	else if (n > 9)
	{
		ft_putnbr_fd_return(n / 10, fd, flags);
		ft_putnbr_fd_return(n % 10, fd, flags);
	}
	else
		ft_putchar_fd_return(n + '0', fd, flags);
	return (ft_intlen(n, 10) - 1);
}
