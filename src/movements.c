/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:30:52 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/13 15:00:29 by albagarc         ###   ########.fr       */
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
	first->next = third;
	third->previous = first;
	*stack = second;

}
