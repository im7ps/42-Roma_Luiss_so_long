/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:30:31 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:24 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	ch;

	ch = (char) c;
	string = (char *) s;
	while (string != NULL && n--)
	{
		if (*string == ch)
			return (string);
		else
			string++;
	}
	return (NULL);
}
