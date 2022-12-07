/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:23:08 by albagarc          #+#    #+#             */
/*   Updated: 2022/05/20 19:16:13 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1a;
	const unsigned char	*s2a;

	s1a = (const unsigned char *) s1;
	s2a = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1a[i] != s2a[i])
			return (s1a[i] - s2a[i]);
		i++;
	}
	return (0);
}
