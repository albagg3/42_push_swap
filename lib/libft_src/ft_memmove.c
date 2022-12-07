/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:58:03 by albagarc          #+#    #+#             */
/*   Updated: 2022/05/18 11:39:29 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (d == s || len == 0)
		return (dst);
	if (d > s)
	{	
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}	
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
