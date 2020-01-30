/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 10:31:37 by bdekonin       #+#    #+#                */
/*   Updated: 2019/11/26 16:01:21 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ftt_memcpy is the same as ft_memcpy but it also puts an endline on it.
*/

static void	*ftt_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	char		*ptr2;

	ptr1 = (char*)src;
	ptr2 = (char*)dst;
	i = 0;
	if (ptr1 == 0 && ptr2 == 0)
		return (0);
	while (i < n)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	ptr2[i] = '\0';
	return (ptr2);
}

char		*ft_strdup(const char *s1)
{
	char	*s1_dup;
	char	*s2;

	s1_dup = (char*)s1;
	s2 = (char*)malloc(sizeof(char) * ft_strlen(s1_dup) + 1);
	if (s2 == NULL)
		return (0);
	return (ftt_memcpy(s2, s1_dup, ft_strlen(s1_dup)));
}
