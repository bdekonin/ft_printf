/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_convert_pointer.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 05:47:29 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

/*
** This function is used to check if the given arguments has failed.
** if the function has failed it will set my struct error on -1.
** ans from there on i have everything setup that if the flags->error is equal,
** to -1 it will eventually just quit the program while also having everything,
** else freed.
*/

int			checkerror(char *str, char *hex, t_flag *flags, int bool)
{
	if (bool == 0 && !str)
	{
		flags->error = -1;
		return (-1);
	}
	else if (bool == 1 && !str)
	{
		free(hex);
		flags->error = -1;
		return (-1);
	}
	return (0);
}

/*
** I first check if the addition is a uppercase or lowercase.
** I do that on line 49. and change the value of zero_x based on that.
** I malloc the amount using intlen base 16. the 0x part doesnt have to be,
** malloced because I already did that at the funtion "ft_printf.c".
** My converter from decimal to hex works backworks, So i set a endline myself
** I set flags->putnbr on 1 so my printer knows when to print out the "0x".
** Then I do multiple checks to see in which categorize it falls into.
** then i free hex, and i return the function with 1.
*/

int			ft_hex_convert_pointer(unsigned long long ans, unsigned \
long long addition, t_flag *flags)
{
	char	*hex;

	if (addition == 55)
		flags->zero_x[1] = 'X';
	hex = malloc(sizeof(char) * ft_intlen_unsigned(ans, 16));
	if (checkerror(hex, hex, flags, 0) == -1)
		return (-1);
	hex[ft_intlen_unsigned(ans, 16) - 1] = '\0';
	hex = ft_hex_converting(hex, ans, addition);
	flags->putnbr_neg = 1;
	if (flags->flag_type == 0 && flags->prec_bool == 0 && \
	flags->precision == -1)
	{
		if (ans != 0)
			ft_putnbr_print_pointer(hex, 1, flags);
		else
			ft_putnbr_print_pointer("0", 1, flags);
	}
	else if (flags->flag_type != 0 && flags->prec_bool == 0 && \
	flags->precision == -1 && ans == 0)
		ft_putnbr_print_pointer("0", 1, flags);
	else
		ft_putnbr_print_pointer(hex, 1, flags);
	free(hex);
	return (0);
}
