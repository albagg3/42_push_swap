/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:03:16 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/12 17:37:37 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/errors.h"
#include "../lib/libft_src/libft.h"
#include "../inc/utils.h"
#include <stdio.h>
void	print_list (t_element **list);

int	main(int argc, char **argv)
{
	t_element	*a;
	t_element *temp;
	int i;
	

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
	print_list(&a);
}


void	print_list (t_element **list)
{
	t_element *temp;
	temp = *list;
	while (temp)
	{
		printf("valor en lista:%d, valor en index:%d\n", temp->value, temp->index);
		temp = temp->next;
	}
}
