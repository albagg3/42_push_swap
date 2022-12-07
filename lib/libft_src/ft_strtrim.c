/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:32:31 by albagarc          #+#    #+#             */
/*   Updated: 2022/05/27 15:53:36 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		count;
	int		s1_len;

	count = 0;
	s1_len = ft_strlen(s1);
	while (s1[count] && ft_strchr(set, s1[count]))
	{
		count++;
	}
	while (*s1 && ft_strchr(set, s1[s1_len - 1]))
	{
		s1_len--;
	}
	new = ft_substr(s1, count, (s1_len - count));
	return (new);
}
