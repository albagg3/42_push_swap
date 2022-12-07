/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:13:13 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/07 09:36:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	while (*lst != NULL)
	{
		temp = *lst;
		while (temp != NULL)
		{
			(del)(temp -> content);
			new = temp -> next;
			free (temp);
			temp = new;
		}
		*lst = NULL;
	}
}
