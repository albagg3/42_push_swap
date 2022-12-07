/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:49:59 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/08 11:47:25 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	unsigned int	cont;

	cont = 0;
	i = ft_strlen(s) - start;
	if (len >= i && start < ft_strlen(s))
		len = i;
	else if (start >= ft_strlen(s))
		len = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (cont < len)
	{
		new[cont] = s[start];
		cont++;
		start++;
	}
	new[cont] = '\0';
	return (new);
}
