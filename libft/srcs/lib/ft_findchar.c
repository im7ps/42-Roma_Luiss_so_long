/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:21:05 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/21 20:06:42 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Questa funzione è stata creata appositamente per so_long, da non
//usare per altri pmi, ritorna 0 in caso di fallimento, 1 altrimenti

#include	"../../includes/libft.h"
#include <stdio.h>

int	ft_findchar(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] != (char) c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
