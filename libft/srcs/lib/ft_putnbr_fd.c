/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:21:26 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:40 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	b;

	b = n;
	if (b < 0)
	{
		ft_putchar_fd('-', fd);
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putnbr_fd(b % 10, fd);
	}
	else
		ft_putchar_fd(b + '0', fd);
}
