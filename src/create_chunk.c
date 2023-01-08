/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:02 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/08 16:06:38 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"

//Esta función mira a ver cual es el minimo index del chunk para saber el rango del chunk.  es decir si estamos en 0-19 o 20-9 etc.
int	chunk_range(t_element **stack_b)
{
	int	min_in_chunk;
	int	n;
	
	min_in_chunk = 20;
	if(!*stack_b || lst_size(*stack_b) < 20)
		min_in_chunk = 0;
	else
	{
		n = lst_size(*stack_b) / 20;
		min_in_chunk *= n;
	}
	return (min_in_chunk);

}
/*int	min_chunk(t_element **stack_b, int len)
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
}*/

// una vez que vamos pasando numeros al stack_b colocamos los mas altos de cada chunk mas arriba que los mas bajos de cada chunk ( hasta conseguir la forma de reloj de arena en el stack_b)

void	organize_stack_b(t_element **stack_b, t_element **stack_a)
{
	int max_in_chunk;
	int min_in_chunk;
	int total_len;

	if(lst_size(*stack_b) == 1 || lst_size(*stack_b) == 0)
		return ;
	total_len = lst_size(*stack_a) + lst_size(*stack_b);
//	max_in_chunk = min_chunk(stack_b, total_len ) + total_len / 4; 
	max_in_chunk = chunk_range(stack_b) + 20;
       	min_in_chunk = chunk_range(stack_b);	
	if(total_len < 20)
		max_in_chunk = total_len;
	if((*stack_b)->index < min_in_chunk + 10)
	{
		if(*stack_a && (*stack_a)->index > max_in_chunk)
			print_do_rotate(stack_a, stack_b, 'a', 'b');
		else
			print_do_rotate(0, stack_b, 0, 'b');

	}
}

//si el numero es parte de un chunk lo pushea a la stack_b
//luego organiza el stack_b y volvemos al siguiente numero de la lista con una length menos
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
	organize_stack_b(stack_b, stack_a);
	length--;
 	return length;	
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
//		min_in_chunk = min_chunk(stack_b, len);
		min_in_chunk = chunk_range(stack_b);
		if (t->index >= min_in_chunk && t->index < min_in_chunk + 20)
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


