/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:41:05 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/12 17:37:28 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../inc/defines.h"
#include "../inc/errors.h"
#include <stdio.h>


t_element	*lst_new(int content)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (0);
	new -> value = content;
	new -> next = NULL;
	new -> previous = NULL;
	return (new);
}

t_element	*lst_last(t_element *lst)
{
	if (lst != NULL)
		while (lst -> next != NULL)
			lst = lst -> next;
	return (lst);
}

void	lst_add_back(t_element **first, t_element *new_el)
{
	t_element	*temp;

	if (*first == NULL)
		*first = new_el;
	else
	{
		temp = lst_last(*first);
		temp -> next = new_el;
		new_el -> previous = temp;
	}
}

void	set_index(t_element **first)
{
	t_element *temp;
	t_element *compare;
	int i;

	i = 0;
	temp = *first;
	compare = temp->next;
	
	while(temp)
	{
		
		compare = temp->next;
		while (compare)
		{
			if(temp->value < compare->value)
			{
				temp->index = i;
				compare = compare->next;
			}
			else
			{
				temp = compare;
				temp->index = i;
				compare = temp->next;
			}
		}
		temp = temp -> next;
		i++;
	}
}

