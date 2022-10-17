/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:52:29 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/17 19:05:39 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*stack;
	int		i;

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
