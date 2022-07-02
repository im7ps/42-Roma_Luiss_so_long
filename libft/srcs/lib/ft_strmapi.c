/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:36:33 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:48:07 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	size_t	i;

	if (!s)
		return (NULL);
	d = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
