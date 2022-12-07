/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:29:26 by albagarc          #+#    #+#             */
/*   Updated: 2022/05/22 09:41:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	size_t	i;
	char	*mip;

	mip = (char *)s;
	i = 0;
	while (i < n)
	{
		if (mip[i] == ((char)c))
			return (((unsigned char *)s) + i);
		i++;
	}
	return (0);
}
