/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:41:05 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/13 15:00:32 by albagarc         ###   ########.fr       */
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

	temp = *first;
	while(temp)
	{
		i = 0;
		compare = *first;
		while (compare)
		{
			if(temp->value > compare->value)
			{
				i++;
			}
			compare = compare->next;
		}
		temp->index = i;
		temp = temp -> next;
	}
}

