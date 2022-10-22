/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:11:33 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/22 22:57:54 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//x sono le colonne quindi j
//y sono le righe quindi i

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
			if (map_p.map[i][j] == 'P')
			{
				p->element[0].pos.x = j * 128;
				p->element[0].pos.y = i * 128;
				p->element[0].sprite.ptr = p->sprite.ptr;
			}
			if (map_p.map[i][j] == '0')
			{
				p->element[1].sprite.ptr = p->sprite.ptr;
			}
			if (map_p.map[i][j] == 'C')
			{
				p->element[2].sprite.ptr = p->sprite.ptr;
			}
			if (map_p.map[i][j] == 'E')
			{
				p->element[3].pos.x = j * 128;
				p->element[3].pos.y = i * 128;
				p->element[3].sprite.ptr = p->sprite.ptr;
			}
			if (map_p.map[i][j] == '1')
			{
				p->element[4].sprite.ptr = p->sprite.ptr;
			}
			mlx_put_image_to_window(p->mlx, p->window.ptr, p->sprite.ptr, p->sprite_pos.x, p->sprite_pos.y);
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

int	ft_strlen2(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_count_cols(const char *map_model)
{
	int		fd;
	int		cols;
	char	*buffer;

	cols = 0;
	buffer = malloc(sizeof(char) * (1));
	fd = open(map_model, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Errore in upload map\n");
		return (1);
	}
	while (*buffer != '\n')
	{
		read(fd, buffer, 1);
		if (*buffer == '\0')
		{
			free(buffer);
			buffer = NULL;
			return (0);
		}
		cols++;
	}
	close(fd);
	free(buffer);
	buffer = NULL;
	return (cols);
}

int	upload_map(t_map *map_ptr, const char *map_model)
{
	int	fd;
	int	i;

	map_ptr->rows = ft_count_rows(map_model);
	ft_printf("ROWS %d\n", map_ptr->rows);
	//map_ptr->cols = ft_count_cols(map_model);
	fd = open(map_model, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Errore in upload map\n");
		return (1);
	}
	map_ptr->map = (char **) malloc (sizeof(char *) * (map_ptr->rows + 1));
	ft_printf("MAP[0] pre %p\n", map_ptr->map);
	i = 0;
	ft_printf("%d\n",  map_ptr->rows);
	while (i < map_ptr->rows)
	{
		//map_ptr->map[i] = malloc (sizeof(char *) * (map_ptr->cols + 1));
		map_ptr->map[i] = get_next_line(fd, 1);
		ft_printf("MAP %p \"%s\"\n", map_ptr->map[i], map_ptr->map[i]);
		fflush(stdout);
		i++;
	}
	map_ptr->map[i] = NULL; 
	ft_printf("MAP[0] post %p | %d\n", map_ptr->map, i);
	close(fd);
	//if (check_map_errors(map_ptr, map_model) == 1)
	//{
	//	ft_printf("Error\n");
	//	return (1);
	//}
	//else
	//	ft_printf("Valid\n");
	return (0);
}
