/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:30:52 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/13 18:46:09 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <stddef.h>

void	swap_element(t_element **stack)
{
	t_element *first;
	t_element *second;
	t_element *third;
	

	first = *stack;
	second = first->next;
	third = second->next;
	
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	if(third)
	{
		first->next = third;
		third->previous = first;
	}
	else
		first->next = NULL;
	*stack = second;

}

void	push_element(t_element **stack_1, t_element **stack_2)
{
	t_element *first_1;
	t_element *first_2;

	first_1 = *stack_1;
	first_2 = *stack_2;
	if (first_2 == NULL)
	{
		first_1->next->previous = NULL;
		*stack_1 = first_1->next;
		*stack_2 = first_1;
		first_1->next = NULL;
	}
	if (first_2)
	{
		if(first_1->next == NULL) 
			*stack_1 = NULL;
		else
		{
			first_1->next->previous = NULL;
			*stack_1 = first_1->next;
		}
		first_2->previous = first_1;
		first_1->next = first_2;
		*stack_2 = first_1;
	}
}

void	reverse_rotate_element(t_element **stack)
{

}

void	rotate_element(t_element **stack)
{

}
