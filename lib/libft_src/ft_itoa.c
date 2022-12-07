/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:19:37 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/01 14:58:54 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len = 1;
		while (n)
		{
			n = n / 10;
			len++;
		}
	}
	if (n > 0)
	{
		len = 0;
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	mivalor;

	mivalor = n;
	len = ft_len(mivalor);
	result = ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (0);
	if (mivalor == 0)
		result[len - 1] = '0';
	if (mivalor < 0)
	{
		*result = '-';
		mivalor = -mivalor;
	}
	while (mivalor > 0 && len - 1 >= 0)
	{
		result[len - 1] = mivalor % 10 + '0';
		len --;
		mivalor = mivalor / 10;
	}
	return (result);
}
