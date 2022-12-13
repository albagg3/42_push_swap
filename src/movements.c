/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:30:52 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/13 13:45:59 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <stddef.h>

void	swap_element(t_element **stack)
{
	t_element *temp;
	t_element *first;
	t_element *second;
	t_element *third;
	

	first = *stack;
	second = first->next;
	temp = second;
	third = second->next;

	temp->previous = NULL;
	temp->next = first;
	first->previous = temp;
	first->next = third;
	third->previous = first;
	*stack = temp;

}
