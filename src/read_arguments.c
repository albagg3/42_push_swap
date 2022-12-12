/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:27 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/12 15:33:04 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft_src/libft.h"
#include "../inc/errors.h"
#include <stdio.h>

//Comprobamos que lo que hay es un numero

int ft_is_number(char *str)
{
	int i;

	i = 0;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-' || str[i] == '+')
		i++;
	if(str[i] != '\0')
	{
		while(str[i])
		{
			if(!ft_isdigit(str[i]))
			{
				terminate(ERR_NBR);
				return(0);
			}
			i++;
		}
		return(1);
	}
	terminate(ERR_NBR);
	return(0);
}

//Comprobamos si es un int con su max y su min

int ft_is_int(char *str)
{
	if(ft_strlen(str) <= 11)
	{
		if(ft_strlen(str) == 11 && ft_strncmp(str, "-2147483648", 11) >  0)
		{
			terminate(ERR_INT);
			return(0);
		}
		if(ft_strlen(str) == 10 && ft_strncmp(str, "2147483647", 10) > 0)
		{
			terminate(ERR_INT);
			return(0);
		}
		return (1);
	}
	terminate(ERR_INT);
	return(0);
	
}

//Comprobamos si están duplicados

void ft_is_dup(char **argv, int length)
{
	int	i;
	int	j;

	i = 1;
	while (length)
	{

		j = 1;
		while((ft_is_number(argv[i]) && ft_is_int(argv[i])) && j < length)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j + i]))
			{
				terminate(ERR_ARGSRP);
			}
			else
				j++;
		}
		i++;
		length--;
	}
}

//atoi y si no es un numero valido o no es un numero ya salimos del programa 
//si es un numero valido creamos un elemento de la lista
//
/*
void	read_arguments(char	**argv )
{	
	ft_is_dup
	if (ft_atoi(num))
	{
		if(!a->first)
			ft_lstnew(ft_atoi(num));
		else
			ft_lstadd_back(a, a->first)
				
	}

}*/
