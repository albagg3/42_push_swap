/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:14:30 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/09 10:13:43 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char	const *s, char c)
{
	int	count;
	int	n_word;

	count = 0;
	n_word = 0;
	while (s[count])
	{
		if (s[count] != c && ((s[count + 1] == c) || s[count + 1] == '\0'))
			n_word++;
		count++;
	}
	return (n_word);
}

char	**ft_free(char **result, int n_word)
{
	while (n_word > 0)
	{
		n_word--;
		free(result[n_word]);
	}
	free(result);
	return (0);
}

char	**ft_findposition_cutstring(char	const *s, char c, char **result)
{
	int		n_word;
	int		count;
	int		start;

	n_word = 0;
	count = 0;
	while (s[count])
	{
		if (count == 0 && s[count] != c)
			start = count;
		if (count > 0 && s[count] != c && s[count -1] == c)
			start = count;
		if (s[count] != c && ((s[count + 1] == c) || s[count + 1] == '\0'))
		{
			result[n_word] = ft_substr(s, start, count - start + 1);
			if (!result[n_word])
				return (ft_free(result, n_word));
			n_word++;
		}
		count++;
	}
	result[n_word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	result = ft_findposition_cutstring(s, c, result);
	return (result);
}
