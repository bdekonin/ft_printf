/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd_unsigned.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 06:52:58 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_putnbr_fd_return_unsigned(unsigned int n, int fd, t_flag *flags)
{
	if (flags->error == -1)
		return (0);
	if (n < 0)
	{
		n = 4294967295 - n;
		ft_putnbr_fd_return(n, fd, flags);
	}
	else if (n > 9)
	{
		ft_putnbr_fd_return(n / 10, fd, flags);
		ft_putnbr_fd_return(n % 10, fd, flags);
	}
	else
		ft_putchar_fd_return(n + '0', fd, flags);
	if (n == 0)
		return (1);
	else
		return (ft_intlen((long)n, 10) - 1);
}
