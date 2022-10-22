/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:09:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/22 23:00:36 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_count_rows(const char *map)
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
	if (row == NULL)
	{
		return (0);
	}
	while (row)
	{
		counter++;
		free(row);
		row = get_next_line(fd, 1);
		free(row);
	}
	close(fd);
	return (counter);
}

char ft_find_last(t_map  *map_ptr, const char *map_model)
{
	int i;
	int j;
		
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
	if (map_ptr->map[i-1][j-1] == '\n')
		return (map_ptr->map[i-1][j-1]);
	return (map_ptr->map[i-1][j]); 
}

void	moves_counter(void	*mlx_ptr, void	*win_ptr)
{
	int x = 30;
	int y = 30;
	int color = 0xFFFFFF;
	char *string = "moves counter";
	int wtf;

	wtf = mlx_string_put(mlx_ptr, win_ptr, x, y, color, string);
	printf("non so cosa sia ma mlx_string_put vale: %d\n", wtf);
}
