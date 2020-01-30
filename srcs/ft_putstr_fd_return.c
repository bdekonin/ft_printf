/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd_return.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 06:53:22 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 11:13:42 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_putstr_fd_return(char *s, int fd, t_flag *flags)
{
	int i;

	i = 0;
	s = (s == NULL) ? "(null)" : s;
	while (s[i] != '\0' && flags->error != -1)
	{
		ft_putchar_fd_return(s[i], fd, flags);
		i++;
	}
	return (i);
}
