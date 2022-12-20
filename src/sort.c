/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:33 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/20 19:07:08 by albagarc         ###   ########.fr       */
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

int min_index_in_stack(t_element **stack)
{
	t_element *temp;
	int i;
	
	temp = *stack;
	i= temp->index;
	while(temp)
	{
		if(i > temp->index)
			i = temp->index;
		temp=temp->next;
	}
	return (i);

}

int	is_not_sorted(t_element **stack)
{
	t_element *temp;
	int i;
	
	temp = *stack;
	i= min_index_in_stack(stack);
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





void	sort_3(t_element **stack, int length, int min_index)
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
		while(is_not_sorted(stack))
		{
			temp = *stack;
			if((temp->index == min_index && temp->next->index == min_index + 2) || \
				(temp->index == min_index + 2 && temp->next->index == min_index + 1) || \
					(temp->index == min_index + 1 && temp->next->index == min_index))
				print_do_swap(stack, 0, 'a', 0);
			else if(temp->index == min_index + 2 && temp->next->index == min_index)
				print_do_rotate(stack, 0, 'a', 0);
			else 
				print_do_rrotate(stack, 0, 'a', 0);
		}
	}
}

/*void	sort_5_stack_b(t_element **stack_1, t_element **stack_2)
{
	t_element *a;
	t_element *b;

	a = *stack_1;
	b = *stack_2;
	if((b->next == NULL && b->index == 0) || (b->next->index == 0 && b->index == 1))
		print_do_push(stack_2, stack_1, 'a');
	else if((b->next == NULL && b->index == 1) || (b->next != NULL && b->index == 2))
	{
		print_do_push(stack_2, stack_1, 'a');
		print_do_swap(stack_1, 0, 'a', 0);
	}
	if (b->next->index == 2 && b->index > 2)
	{
		if(b->index == 3)
		{
				print_do_rrotate();
				print_do_push(stack_2, stack_1, 'a');
		}
		if(b->index == 4)
		{
			print_do_push (stack_2, stack_1, 'a');
			print_do_rrotate(a, 0, 'a', 0);
		}
		print_do_push();
		print_do_rotate();
		print_do_rotate();
		print_do_rotate();
	}
	else if(b->next != NULL && b->index == 4 )

}

void	sort_5(t_element **stack_1, t_element **stack_2, int length)
{
	t_element *temp_1;
	t_element *temp_2;

	temp_1 = *stack_1;
	temp_2 = *stack_2;
	if (temp_1->index > temp_1->next->index && (temp_1->index != 4 && temp_1->next->index != 3))
		print_do_swap(stack_1, 0, 'a', 0);
	print_do_push(stack_1, stack_2, 'b', 0);
	print_do_push(stack_1, stack_2, 'b', 0);
	sort_3(stack_1, length);
	while(stack_2)
	{
		sort_5_stack_b(stack_1,stack_2);
	}

}*/
//una funcion que decida si es max index o no
int	is_min(int index)
{
	int min_index;

	min_index = 0;
	if(index == min_index)
			return(1);
	else
		return(0);	
}
int is_next_min(int index)
{
	int min_next_index;

	min_next_index = 1;
	if(index == min_next_index)
			return(1);
	else
		return(0);	
}

int	lst_size(t_element *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
void	sort_5_to_b(t_element **stack_1, t_element **stack_2)
{
	t_element *temp_1;
	t_element *last;

	temp_1 = *stack_1;
	last = lst_last(temp_1);
	while(lst_size(temp_1) > 3)
	{
		if(is_min(temp_1->index) || is_next_min(temp_1->index))
			print_do_push(stack_1,stack_2, 0, 'b');
		else if(is_min(temp_1->next->index) || is_next_min(temp_1->next->index))
			{
				print_do_swap(stack_1, 0, 'a', 0);
				print_do_push(stack_1,stack_2, 0, 'b');
			}
		else if(is_min(last->index) || is_next_min(last->index))
		{
			print_do_rrotate(stack_1, 0, 'a', 0);
			print_do_push(stack_1,stack_2, 0, 'b');
		}
		else
			print_do_rotate(stack_1, 0, 'a', 0);	
		temp_1 = *stack_1;
		last = lst_last(temp_1);

	}
}

void	sort_5(t_element **stack_1, t_element **stack_2)
{
	t_element *temp_2;
	int min_index;
	
	
	temp_2 = *stack_2;
	if(!is_not_sorted(stack_1))
		return ;
	else
	{
		sort_5_to_b(stack_1, stack_2);
		min_index = min_index_in_stack(stack_1);
		sort_3(stack_1, 3, min_index);
		temp_2 = *stack_2;
		if(temp_2->index == 0)
		{
			print_do_swap(0, stack_2, 0, 'b');
			print_do_push(stack_2,stack_1,'a',0);
			print_do_push(stack_2,stack_1,'a',0);
		}
		if(temp_2->index == 1)
		{
			print_do_push(stack_2,stack_1,'a',0);
			print_do_push(stack_2,stack_1,'a',0);
		}
	}
}
