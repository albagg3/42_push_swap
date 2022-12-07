/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:44:46 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/01 11:37:54 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s1) + 1;
	ptr = malloc (sizeof(char) * i);
	if (ptr != NULL)
	{
		ft_memcpy(ptr, s1, i);
		return (ptr);
	}
	return (0);
}
