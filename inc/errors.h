/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:46 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/11 20:32:29 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#define ERR_NOARGS "Error: Please write some numbers"
#define ERR_ARGSRP "Error: Please make sure there are not repeated numbers"
#define ERR_NBR "Error: Please make sure all the inputs are numbers"
#define ERR_INT "Error: Please make sure all the numbers are int"

void	terminate(char *s);

#endif
