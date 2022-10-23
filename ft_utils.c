/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:09:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/23 22:38:04 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(const char *map)
{
	int		counter;
	int		fd;
	char	*row;

	counter = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Mmmm non trovo la mappa\n");
		return (1);
	}
	row = get_next_line(fd, 1);
	while (row)
	{
		free(row);
		row = get_next_line(fd, 1);
		counter++;
	}
	free(row);
	close(fd);
	return (counter);
}

char	ft_find_last(t_map *map_ptr, const char *map_model)
{
	int	i;
	int	j;

	i = 0;
	while (map_ptr->map[i] && i < ft_count_rows(map_model))
	{
		j = 0;
		while (map_ptr->map[i][j])
		{
			j++;
		}
		i++;
	}
	if (map_ptr->map[i - 1][j - 1] == '\n')
		return (map_ptr->map[i - 1][j - 1]);
	return (map_ptr->map[i - 1][j]);
}
