/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_convert.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 15:32:18 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char			*ft_hex_converting(char *hex, unsigned long long ans, unsigned \
long long addition)
{
	long	remainder;
	int		i;

	i = ft_intlen_unsigned(ans, 16) - 2;
	while (ans != 0 && i >= 0)
	{
		remainder = ans % 16;
		if (remainder <= 9)
		{
			hex[i] = remainder + 48;
			i--;
		}
		else
		{
			hex[i] = addition + remainder;
			i--;
		}
		ans = ans / 16;
	}
	return (hex);
}

/*
** function used if is ans is 0
*/

static void		ft_hex_convert_zero(char *hex, t_flag *flags)
{
	free(hex);
	if (flags->precision == 0)
		ft_putnbr_flags_print(ft_strdup("\0"), 1, flags);
	else if ((flags->prec_bool == 0 || flags->precision > 0))
		ft_putnbr_flags_print(ft_strdup("0"), 1, flags);
	else
		flags->total_print += ft_putchar_fd_return('0', 1, flags);
	return ;
}

/*
** First I check if the hashflag isn't 1 and ans isnt equal to 0
** if they both are true. is does the same steps but then in the
** pointer variant.
** then I malloc the amount needed by intlen base 16.
** I use the function checkerror if hex failed. if so it returns -1
** If ans is 0. Then i go to ft_hex_convert_zero
** I use the bool with and without flags.
** 0 is without any flags, and 1 is with flags.
** And since i free hex in ft_putnbr_flags_print at the end. I dont
** want to do it again.
*/

int				ft_hex_convert(unsigned int ans, unsigned int addition, \
int bool, t_flag *flags)
{
	char *hex;

	if (flags->hash_flag == 1 && ans != 0)
	{
		flags->putnbr_neg = 1;
		ft_hex_convert_pointer((unsigned long)ans, addition, flags);
		return (0);
	}
	hex = malloc(sizeof(char) * ft_intlen(ans, 16));
	if (checkerror(hex, hex, flags, 0) == -1)
		return (-1);
	if (ans == 0)
	{
		ft_hex_convert_zero(hex, flags);
		return (0);
	}
	hex[ft_intlen(ans, 16) - 1] = '\0';
	hex = ft_hex_converting(hex, ans, addition);
	if (bool == 0 && flags->error != -1)
		flags->total_print += ft_putstr_fd_return(hex, 1, flags);
	else if (bool == 2 && flags->error != -1)
		ft_putnbr_flags_print(hex, 1, flags);
	if (bool != 2)
		free(hex);
	return (0);
}
