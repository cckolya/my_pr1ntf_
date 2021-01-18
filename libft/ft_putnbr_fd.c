/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 05:02:24 by cclock            #+#    #+#             */
/*   Updated: 2020/11/08 18:57:33 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd, int flag)
{
	char c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		if (flag == 1)
		{
			write(fd, "-", 1);
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, flag);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}