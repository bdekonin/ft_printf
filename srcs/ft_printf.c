/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:14:22 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 11:39:48 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	int			backup;
	va_list		argp;
	t_flag		*flags;

	va_start(argp, format);
	i = 0;
	flags = malloc(sizeof(t_flag));
	if (!flags)
		return (-1);
	flags->zero_x = ft_strdup("0x");
	if (!flags->zero_x)
	{
		free(flags);
		return (-1);
	}
	flags->total_print = 0;
	flags = ft_structset(flags);
	ft_checkformat(format, flags, i, argp);
	backup = (flags->error == -1) ? -1 : flags->total_print;
	free(flags->zero_x);
	free(flags);
	return (backup);
}
