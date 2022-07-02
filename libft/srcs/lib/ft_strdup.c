/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:54 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:52 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	dim;
	char	*stack;

	dim = ft_strlen(s1) + 1;
	stack = malloc(dim);
	if (s1 == NULL)
		return (NULL);
	else
		ft_memcpy(stack, s1, dim);
	return (stack);
}
