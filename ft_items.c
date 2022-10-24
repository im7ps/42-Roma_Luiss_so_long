/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_items.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:36 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/24 16:32:56 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	items_counter(char c)
{
	static int	p_toggler;
	static int	e_toggler;
	static int	c_toggler;

	if (c == 'P')
		p_toggler++;
	else if (c == 'E')
	{
		e_toggler++;
		return (1);
	}
	else if (c == 'C')
	{
		c_toggler++;
		return (c_toggler);
	}
	return (p_toggler);
}

void	ft_items_checker_help(t_map *map_ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_ptr->rows && map_ptr->map[i])
	{
		j = -1;
		while (map_ptr->map[i][++j] != '\0')
		{
			if (map_ptr->map[i][j] == 'P')
				map_ptr->p = items_counter(map_ptr->map[i][j]);
			else if (map_ptr->map[i][j] == 'E')
				map_ptr->e = items_counter(map_ptr->map[i][j]);
			else if (map_ptr->map[i][j] == 'C')
				map_ptr->c = items_counter(map_ptr->map[i][j]);
			else if (map_ptr->map[i][j] == '0')
				map_ptr->f++;
		}
		i++;
	}
}

int	items_checker(t_map *map_ptr, const char *map_model)
{
	map_ptr->e = 0;
	map_ptr->c = 0;
	map_ptr->p = 0;
	map_ptr->f = 0;
	map_ptr->rows = ft_count_rows(map_model);
	ft_items_checker_help(map_ptr);
	if (map_ptr->p != 1 || map_ptr->e != 1 || \
		map_ptr->c == 0 || map_ptr->f == 0)
		return (1);
	return (0);
}
