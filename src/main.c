/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:03:16 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/11 20:27:04 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/errors.h"
#include "../inc/utils.h"

int	main(int argc, char **argv)
{
//	t_stack	stack_a;
//	int i;

//	i = 0;
	//si solo hay un numero que hay que hacer ahora mismo entra en el if

	if (argc >= 2)
	{
		ft_is_dup(argv, argc -1);
		
	}
	else
		terminate(ERR_NOARGS);
}
