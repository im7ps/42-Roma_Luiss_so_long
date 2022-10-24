/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:11:33 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/24 18:31:34 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_texture_helper(t_p *p, int i, int j)
{
	if (p->map_p.map[i][j] == 'P')
		ft_load_player(p, i, j);
	if (p->map_p.map[i][j] == '0')
		ft_load_floor(p);
	if (p->map_p.map[i][j] == 'C')
		ft_load_coin(p);
	if (p->map_p.map[i][j] == 'E')
		ft_load_exit(p, i, j);
	if (p->map_p.map[i][j] == '1')
		p->e[4].sprite.ptr = p->sprite.ptr;
}

void	ft_load_textures(t_p *p, t_map map_p, const char *map_model)
{
	int	i;
	int	j;
	int	cols;
	int	rows;

	cols = ft_strlen(map_p.map[0]) - 1;
	rows = ft_count_rows(map_model);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			p->sprite = ft_new_sprite(p->mlx, map_p.map[i][j]);
			p->sprite_pos.x = j * 128;
			p->sprite_pos.y = i * 128;
			ft_texture_helper(p, i, j);
			mlx_put_image_to_window(p->mlx, p->window.ptr, p->sprite.ptr, \
				p->sprite_pos.x, p->sprite_pos.y);
			j++;
		}
		i++;
	}
}

int	check_map_errors(t_map *map_ptr, const char *map_model)
{
	if (empty_or_invalid_checker(map_ptr, map_model) != 0)
	{
		ft_printf("Empty\n");
		return (1);
	}
	if (rectangle_checker(map_ptr, map_model) != 0)
	{
		ft_printf("Triangle\n");
		return (1);
	}
	if (walls_checker(map_ptr, map_model) != 0)
	{
		ft_printf("No walls\n");
		return (1);
	}
	if (items_checker(map_ptr, map_model) != 0)
	{
		ft_printf("Items wrong\n");
		return (1);
	}
	return (0);
}

int	upload_map(t_map *map_ptr, const char *map_model)
{
	int	fd;
	int	i;

	map_ptr->rows = ft_count_rows(map_model);
	fd = open(map_model, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Errore in upload map\n");
		return (1);
	}
	map_ptr->map = (char **) malloc (sizeof(char *) * (map_ptr->rows + 1));
	i = 0;
	while (i < map_ptr->rows)
	{
		map_ptr->map[i] = get_next_line(fd, 1);
		i++;
	}
	map_ptr->map[i] = NULL;
	close(fd);
	if (check_map_errors(map_ptr, map_model) == 1)
		return (1);
	return (0);
}
