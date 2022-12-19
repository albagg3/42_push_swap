/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:33 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/19 12:08:22 by albagarc         ###   ########.fr       */
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
		{
			return(1);
		}
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
		while(is_sorted(stack))
		{
			temp = *stack;
			if((temp->index == 0 && temp->next->index == 2) || \
				(temp->index == 2 && temp->next->index == 1) || \
					(temp->index == 1 && temp->next->index ==0))
				print_do_swap(stack, 0, 'a', 0);
			else if(temp->index == 2 && temp->next->index == 0)
				print_do_rotate(stack, 0, 'a', 0);
			else 
				print_do_rrotate(stack, 0, 'a', 0);
		}
	}
}


void	sort_5(t_element **stack_1, t_element **stack_2, int length)
{
	t_element *temp_1;
	t_element *temp_2;

	temp_1 = *stack_1;
	temp_2 = *stack_2;
	if (temp_1->index > temp_1->next->index)
		print_do_swap(stack_1, 0, 'a', 0);
	print_do_push(stack_1, stack_2, 'b', 0);
	print_do_push(stack_1, stack_2,'a', 0);
	sort_3(stack_1, length);
	print_do_push(stack_2, stack_1, 0, 'b');
	if(temp_1-)

}
//una funcion que decida si es max index o no
int	get_max_index(t_element **stack)
{
	t_element *temp;
	int max_index;

	max_index = 0;
	temp = *stack;
	while(temp)
	{
		if(temp->index > max_index)
			max_index = temp->index;
		temp = temp -> next;

	}
	return(max_index);
}
