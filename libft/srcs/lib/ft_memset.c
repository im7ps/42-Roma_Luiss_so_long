/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:17:46 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:33 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	l;
	char	*k;

	k = str;
	l = c;
	while (len--)
	{
		*k++ = l;
	}
	return (str);
}
