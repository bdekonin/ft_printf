/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 11:09:27 by bdekonin       #+#    #+#                */
/*   Updated: 2019/11/26 16:01:26 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + \
	ft_strlen(s2) + 1));
	if (str == NULL)
		return (0);
	while ((char)s1[i] != '\0')
	{
		str[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j] != '\0')
	{
		str[i + j] = (char)s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
