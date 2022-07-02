/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:34:30 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:45 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	**fill_m(const char *s, char c, char	**matrix, int num_w)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (j < num_w)
	{
		while (s[i] == c)
				i++;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		if (len != 0)
		{
			matrix[j] = ft_substr(s, i, len);
			j++;
		}
		i += len;
		len = 0;
	}
	return (matrix);
}

int	count_w(char *str, char c)
{
	int	num;
	int	toggle;

	num = 0;
	toggle = 0;
	while (*str)
	{
		if (*str != c && toggle == 0 && *str != '\0')
		{
			toggle = 1;
			num++;
		}
		else if (*str == c)
			toggle = 0;
		str++;
	}
	return (num);
}

char	**ft_split(char const *s, char c)
{
	int		num_w;
	char	**matrix;
	int		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	num_w = count_w((char *)s, c);
	matrix = (char **) malloc(sizeof(char *) * (num_w + 1));
	if (!matrix)
		return (NULL);
	matrix[num_w] = NULL;
	matrix = fill_m(s, c, matrix, num_w);
	return (matrix);
}
