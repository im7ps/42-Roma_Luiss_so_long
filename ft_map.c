/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:11:33 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/17 18:16:26 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_load_textures(t_program program, t_map  map_p, const char *map_model)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < ft_count_rows(map_model))
	{
		j = 0;
		while (j < ft_strlen(map_p.map[0]) - 1)
		{
			ft_printf("CURRENT: %c\n", map_p.map[i][j]);
			program.sprite = ft_new_sprite(program.mlx, map_p.map[i][j]);
			program.sprite_position.x = i * 128;
			program.sprite_position.y = j * 128;
			mlx_put_image_to_window(program.mlx, program.window.pointer, program.sprite.pointer, program.sprite_position.y, program.sprite_position.x);
			j++;
		}
		i++;
	}
}

int	check_map_errors(t_map  *map_ptr, const char *map_model)
{
	if (empty_or_invalid_checker(map_ptr, map_model) != 0)
		return (1);
	if (rectangle_checker(map_ptr, map_model) != 0)
		return (1);
	if (walls_checker(map_ptr, map_model) != 0)
		return (1);
	if (items_checker(map_ptr, map_model) != 0)
		return (1);
	return (0);
}

int	upload_map(t_map  *map_ptr, const char *map_model)
{
	int	fd;
	int	i;

	i = -1; //i = -1 così posso risparmiare un rigo e aumentare la i nella condizione del while 4 righe in basso
	map_ptr->rows = ft_count_rows(map_model);
	fd = open(map_model, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Errore in upload map\n");
		return (1);
	}
	map_ptr->map = (char **) malloc (sizeof(char *) * (map_ptr->rows + 1));
	while (i++ < map_ptr->rows - 1)
		map_ptr->map[i] = get_next_line(fd, 1);
	close(fd);
	if(check_map_errors(map_ptr, map_model) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
		ft_printf("Valid\n");
	return (0);
}
