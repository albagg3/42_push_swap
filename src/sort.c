/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:33 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/21 17:01:50 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>

void	print_list1(t_element **list_a)
{
	t_element	*temp_a;

	temp_a = *list_a;
	while (temp_a)
	{
		temp_a = temp_a->next;
	}
}

int	min_index_in_stack(t_element **stack)
{
	t_element	*temp;
	int			i;

	temp = *stack;
	i = temp->index;
	while (temp)
	{
		if (i > temp->index)
			i = temp->index;
		temp = temp->next;
	}
	return (i);
}

int	is_not_sorted(t_element **stack)
{
	t_element	*temp;
	int			i;

	temp = *stack;
	i = min_index_in_stack(stack);
	while (temp)
	{
		if (temp->index == i)
		{
			i++;
			temp = temp->next;
		}
		else
			return (1);
	}
	return (0);
}

void	sort_3(t_element **stack, int length, int min_i)
{
	t_element	*t;

	t = *stack;
	if (length == 2)
	{
		if (t->index > t->next->index)
			print_do_swap(stack, 0, 'a', 0);
		else
			return ;
	}
	else
	{
		while (is_not_sorted(stack))
		{
			t = *stack;
			if ((t->index == min_i && t->next->index == min_i + 2) || \
				(t->index == min_i + 2 && t->next->index == min_i + 1) || \
					(t->index == min_i + 1 && t->next->index == min_i))
				print_do_swap(stack, 0, 'a', 0);
			else if (t->index == min_i + 2 && t->next->index == min_i)
				print_do_rotate(stack, 0, 'a', 0);
			else
				print_do_rrotate(stack, 0, 'a', 0);
		}
	}
}

//una funcion que decida si es min index o no
int	is_min(int index)
{
	int	min_index;

	min_index = 0;
	if (index == min_index)
		return (1);
	else
		return (0);
}
int	is_next_min(int index)
{
	int	min_next_index;

	min_next_index = 1;
	if (index == min_next_index)
		return (1);
	else
		return (0);
}

int	lst_size(t_element *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	sort_5_to_b(t_element **stack_1, t_element **stack_2, int length)
{
	t_element	*t;
	t_element	*last;

	t = *stack_1;
	last = lst_last(t);
	while (lst_size(t) > 3)
	{
		if (is_min(t->index) || (is_next_min(t->index) && length != 4))
			print_do_push(stack_1, stack_2, 0, 'b');
		else if (is_min(t->next->index) || (is_next_min(t->next->index) && length != 4))
		{
			print_do_swap(stack_1, 0, 'a', 0);
			print_do_push(stack_1, stack_2, 0, 'b');
		}
		else if (is_min(last->index) || (is_next_min(last->index) && length != 4))
		{
			print_do_rrotate(stack_1, 0, 'a', 0);
			print_do_push(stack_1, stack_2, 0, 'b');
		}
		else
			print_do_rotate(stack_1, 0, 'a', 0);
		t = *stack_1;
		last = lst_last(t);
	}
}

void	sort_5(t_element **stack_1, t_element **stack_2, int length)
{
	t_element	*temp_2;
	int			min_index;

	temp_2 = *stack_2;
	if (!is_not_sorted(stack_1))
		return ;
	sort_5_to_b(stack_1, stack_2, length);
	min_index = min_index_in_stack(stack_1);
	sort_3(stack_1, length - 1, min_index);
	temp_2 = *stack_2;
	if (temp_2->index == 0)
	{
		if (lst_size(temp_2) == 2)
		{
			print_do_swap(0, stack_2, 0, 'b');
			print_do_push(stack_1, stack_2, 'a', 0);
		}
		print_do_push(stack_1, stack_2, 'a', 0);
	}
	if (temp_2->index == 1)
	{
		print_do_push(stack_1, stack_2, 'a', 0);
		print_do_push(stack_1, stack_2, 'a', 0);
	}
}
