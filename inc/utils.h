/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:55:26 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/11 20:12:50 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

//void	read_arguments(char *num, t_stack *arguments);
int	ft_is_number(char *str);
int	ft_is_int(char *str);
void	ft_is_dup(char **argv, int length);
