/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/23 10:44:09 by bdekonin      #+#    #+#                 */
/*   Updated: 2020/04/26 22:01:08 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long long n, int base)
{
	int count;

	count = 1;
	if (n == -2147483648)
		return (12);
	else if (n == 0)
		return (2);
	else if (n == 2147483647)
		return (11);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
