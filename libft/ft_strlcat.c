/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 16:02:37 by bdekonin       #+#    #+#                */
/*   Updated: 2019/11/26 16:01:29 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** i is set to the length of dst so it will continue from there on.
** it will copy src to dst from the index on. (so at the end)
** it will put an null terminator at the end of the new string.
** then j will count the total length of src.
** if dstsize smaller is then i, then it cannot return the total length of dst.
** and also adds J because thats how many times it has been copied over.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = ft_strlen(dst);
	j = 0;
	if (i < dstsize)
	{
		while (j < dstsize - i - 1 && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	while (src[j] != '\0')
		j++;
	if (dstsize <= i)
		return (dstsize + j);
	return (i + j);
}
