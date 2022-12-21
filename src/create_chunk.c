/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:02 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/21 18:56:13 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"

void	create_stack_b(t_element **stack_a,t_element **stack_b, int length)
{
	t_element	*t;
	int			i;
//	int			min_index;

	i = 0;
	t = *stack_a;
	 while (t)
	 {
//		min_index = min_index_in_stack(stack_a); 
		if (t->index >= 0 && t->index <= 10)
		{
//			create_chunk();
			if (i < length / 2)
			{
				while(i)
				{
					print_do_rotate(stack_a, 0, 'a', 0);
					i--;
				}
			}
			if (i > length / 2)
			{
				while(i < length)
				{
					print_do_rrotate(stack_a, 0, 'a', 0);
					i++;
				}
			}
			print_do_push(stack_a, stack_b, 0, 'b');
			length--;
			t = *stack_a;
		}
		i++;
		t = t->next;
	 }
}



