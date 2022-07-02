/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:05:39 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:46:36 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*stack;
	size_t	dimension;

	dimension = count * size;
	stack = (char *) malloc(sizeof(char) * dimension);
	if (!stack)
		return (0);
	else
		ft_bzero(stack, dimension);
	return (stack);
}
