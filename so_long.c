/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:33:26 by sgerace           #+#    #+#             */
/*   Updated: 2022/07/01 20:02:31 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_map_errors(char **map)
{
    int i = 0;

    while (i < 5)
	{
		ft_printf("%s", map[i]);
        i++;
	}
}

char	**upload_map()
{
	int		fd;
	int		counter;
	int		i;
	char	*row;
	char	**map;

	counter = 0;
	i = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	row = get_next_line(fd, 1);
	while (row)
	{
		row = get_next_line(fd, 1);
		counter++;
	}
	close(fd);
	free(row);
	fd = open("./maps/map1.ber", O_RDONLY);
	map = (char **) malloc (sizeof(char *) * (counter + 1));
	while (counter--)
		map[i] = get_next_line(fd, 1);
    close(fd);
	return (map);
}

int main(void)
{
    char **map;

    map = upload_map();
    check_map_errors(map);
}