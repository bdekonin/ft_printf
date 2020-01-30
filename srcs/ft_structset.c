/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_structset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 16:16:42 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_flag	*ft_structset(t_flag *flags)
{
	flags->zero = '0';
	flags->space = ' ';
	flags->minus = '-';
	flags->data_type = 0;
	flags->flag_type = 0;
	flags->precision = -1;
	flags->width_amount = 0;
	flags->width_count = 0;
	flags->prec_bool = 0;
	flags->index_i = 0;
	flags->index_j = 0;
	flags->space_count = 0;
	flags->putnbr_neg = 0;
	flags->plus_flag = 0;
	flags->hash_flag = 0;
	flags->flag_continue = 0;
	flags->prec_point = 0;
	flags->star_point = 0;
	flags->arg_count = -1;
	return (flags);
}
