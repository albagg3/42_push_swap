/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:03:16 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/13 18:45:52 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/errors.h"
#include "../lib/libft_src/libft.h"
#include "../inc/utils.h"
#include <stdio.h>
void	print_list (t_element **list_a, t_element **list_b);

int	main(int argc, char **argv)
{
	t_element	*a;
	t_element	*b;
	t_element *temp;
	int i;
	
	b = NULL;
	i = 1;
	//si solo hay un numero que hay que hacer ahora mismo entra en el if

	if (argc >= 2)
	{
		ft_is_dup(argv, argc -1); //me checkea que todos los argumentos esten bien.
		while(argv[i])
		{
			temp = lst_new(ft_atoi(argv[i]));
			lst_add_back(&a, temp);
			i++;
		}
		set_index(&a);
	}
	else
		terminate(ERR_NOARGS);
//	swap_element(&a);
//	print_list(&a);
//	swap_element(&a);
	push_element(&a, &b);
	push_element(&a, &b);
	push_element(&a, &b);
	print_list(&a, &b);
}


void	print_list (t_element **list_a, t_element **list_b)
{
	t_element *temp_a;
	t_element *temp_b;

	temp_a = *list_a;
	temp_b = *list_b;
	while (temp_a)
	{
		printf("valor en lista_1:%d, valor en index:%d\n", temp_a->value, temp_a->index);
		temp_a = temp_a->next;
	}
	while(temp_b)
	{
		printf("valor en lista_2:%d, valor en index:%d\n", temp_b->value, temp_b->index);
		temp_b = temp_b->next;
	}
}
