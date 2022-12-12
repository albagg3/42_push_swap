/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:59:12 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/12 15:33:01 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_element
{
	int 				value;
	int					index;
	struct s_element 	*next;
	struct s_element	*previous;
}t_element;

/*typedef struct s_stack
{
	t_element *first;
	int	length;
}t_stack;*/

