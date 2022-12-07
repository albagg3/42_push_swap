/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:24:47 by albagarc          #+#    #+#             */
/*   Updated: 2022/06/08 12:02:59 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mivalor;

	mivalor = n;
	if (mivalor == -2147483648)
		write(fd, "-2147483648", 11);
	else if (mivalor < 0)
	{
		ft_putchar_fd('-', fd);
		mivalor = -mivalor;
		ft_putnbr_fd(mivalor, fd);
	}
	else if (mivalor >= 10)
	{
		ft_putnbr_fd(mivalor / 10, fd);
		ft_putnbr_fd(mivalor % 10, fd);
	}
	else
		ft_putchar_fd(mivalor + '0', fd);
}
