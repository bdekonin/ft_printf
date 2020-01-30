/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd_return.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 17:42:28 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <unistd.h>

int	ft_putchar_fd_return(char c, int fd, t_flag *flags)
{
	flags->error = write(fd, &c, 1);
	if (flags->error == -1)
		return (0);
	return (1);
}
