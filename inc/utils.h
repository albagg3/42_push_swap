/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:55:26 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/13 18:43:55 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int			ft_is_number(char *str);
int			ft_is_int(char *str);
void		ft_is_dup(char **argv, int length);
t_element	*lst_new(int content);
t_element	*lst_last(t_element *lst);
void		lst_add_back(t_element **first, t_element *new_el);
void		set_index(t_element **first);
void		swap_element(t_element **swap);
void		push_element(t_element **stack_a, t_element **stack_b);
void		reverse_rotate_element(t_element **stack);
void		reverse_element(t_element **stack);
