/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:02 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/30 18:56:38 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"

//si el numero es parte de un chunk lo pushea a la stack_b

int	is_chunk(t_element **stack_a, t_element **stack_b, int length, int i)
{
	if(i < length / 2)
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
	//despues de pushear analizamos stack_b
	length--;
 	return length;	
}

int	min_chunk(t_element **stack_b, int len)
{
	int	min_in_chunk;
	int 	n;
	
	min_in_chunk = len / 4;
	if(!*stack_b || lst_size(*stack_b) < len / 4)
		min_in_chunk = 0;
	else
	{
		n = lst_size(*stack_b) / (len / 4);
		min_in_chunk *= n;
	}
	return (min_in_chunk);
}

void	create_stack_b(t_element **stack_a,t_element **stack_b, int len)
{
	t_element	*t;
	int		i;
	int 		min_in_chunk;
	int		new_len;
	
	i = 0;
	t = *stack_a;
	new_len = len;
	 while (t)
	 {
		min_in_chunk = min_chunk(stack_b, len);
		if (t->index >= min_in_chunk && t->index < min_in_chunk + len / 4)
		{
			new_len = is_chunk(stack_a, stack_b, new_len, i);
			t = *stack_a;
			i = 0;
		}
		else
		{
			i++;
			t = t->next;
		}
	 }
}


