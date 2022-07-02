/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:52:29 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:48:21 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*stack;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		start = ft_strlen(s);
	if (ft_strlen(s) <= start + len)
		len = ft_strlen(s) - start;
	stack = (char *) malloc (sizeof(char) * len + 1);
	if (!stack)
		return (NULL);
	while (len--)
		stack[i++] = s[start++];
	stack[i] = '\0';
	return (stack);
}
