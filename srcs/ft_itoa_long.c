/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_long.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 14:14:53 by bdekonin       #+#    #+#                */
/*   Updated: 2020/01/17 10:33:47 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

/*
** ft_strcpy_em is an stringcopy without the endline at the end.
** vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
*/

static char		*ft_strcpy_em(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*
** it looks many zeros the int can have with deviding it by 10 each time.
** vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
*/

static int		intlen(long long n)
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
		n /= 10;
		count++;
	}
	return (count);
}

/*
** It looks if N was negative, if so it adds a minus char to the,
** first index of the string. if n is bigger then 9 that means it has 2
** characters which cant be converted right away.
** then is does a recursive with the number devided by 10 so it has 1
** character total.
** then if its smaller then 9 it converts itself to a character. once everyone
** of them has been done.
** it returns the whole string.
** vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
*/

static char		*strconv(char *str, long long n, int i, t_flag *flags)
{
	if (n <= -2147483648 && flags->data_type != 5 && flags->flag_type == 0)
		return (ft_strcpy_em(str, "-2147483648"));
	if (n >= 2147483647 && flags->data_type != 5 && flags->flag_type == 0)
		return (ft_strcpy_em(str, "2147483647"));
	if (n == 0)
		return (ft_strcpy_em(str, "0"));
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n > 9)
	{
		strconv(str, n / 10, i - 1, flags);
	}
	str[i - 1] = n % 10 + '0';
	return (str);
}

char			*ft_itoa_long(long long n, t_flag *flags)
{
	char	*str;
	int		count;

	count = intlen(n);
	str = malloc(sizeof(char) * count);
	if (str == NULL)
	{
		flags->error = -1;
		return (NULL);
	}
	str = strconv(str, n, count - 1, flags);
	str[count - 1] = '\0';
	return (str);
}
