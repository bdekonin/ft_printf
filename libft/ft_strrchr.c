/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:39:22 by bdekonin       #+#    #+#                */
/*   Updated: 2019/11/27 14:19:26 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s1;
	int		i;

	s1 = (char*)str;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == c)
			return (&s1[i]);
		i--;
	}
	return (0);
}
