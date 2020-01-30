/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 14:18:39 by bdekonin       #+#    #+#                */
/*   Updated: 2019/11/27 17:33:31 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** It first looks if the string begins with any specific,
** characters and skips those.
** Then it looks if the number is negative or positive. If it is negative it,
** will change the check to a negative number so it can multiple it by a neg,
** in the end.
** Afterwards is looks if the string index is between 0 and 9 and devides,
** then it does an ans multiple by 10 so it goes up one if the character has,
** been converted on line number 47. and then it returns that value multiply.
** by the negative check.
** on line 45 till 49 it checks if the number can overflow.
** it sets the number to the right number chosen by the check.
*/

int	ft_atoi(const char *str)
{
	long long int ans;
	long long int check;
	long long int i;

	ans = 0;
	check = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		check = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (ans * 10 + str[i] - 48 < ans)
		{
			ans = (-1 * check - 1) / 2;
			return (ans * check);
		}
		ans = (ans * 10) + str[i] - 48;
		i++;
	}
	return (ans * check);
}
