/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:03:39 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/01 16:40:25 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	size_t	dst_len;
	size_t	src_len;
	size_t	j;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = 0;
	i = dst_len;
	if (dstsize == 0 || dstsize < dst_len)
		return (dstsize + src_len);
	else
	{
		while (i < (dstsize - 1) && src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}
