/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:33 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/14 18:42:49 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>

void    print_list1 (t_element **list_a)
{
	t_element *temp_a;
 
	temp_a = *list_a;

	while (temp_a)
	{
		printf("valor en lista_1:%d, valor en index:%d\n", temp_a->value, temp_a->index);
		temp_a = temp_a->next;
	}
}

int	is_sorted(t_element **stack)
{
	t_element *temp;
	int i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		if (temp->index == i)
		{
			i++;
			temp = temp->next;
		}
		else
			return(1);
	}
	return(0);
}



void	sort_3(t_element **stack, int length)
{
	t_element *temp;

	temp = *stack;
	if(length == 2)
	{
		if(temp->index > temp->next->index)
			print_do_swap(stack, 0,'a', 0);
		else
			return ;
	}
	else
	{
	//	while(is_sorted(stack))
	//	{
			if((temp->index == 0 && temp->next->index == 2) || \
				(temp->index == 2 && temp->next->index == 1) || \
					(temp->index == 1 && temp->next->index ==0))
			{
				print_do_swap(stack, 0, 'a', 0);
				print_list1(stack);

			}
			if(temp->index == 2 && temp->next->index == 0)
			{
				print_do_rotate(stack, 0, 'a', 0);
				print_list1(stack);
			}
			if(temp->index == 1 && temp->next->index == 2)
			{
				print_do_rrotate(stack, 0, 'a', 0);
				print_list1(stack);
			}
	//	}
	}
}
