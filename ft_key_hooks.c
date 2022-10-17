/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/17 20:41:31 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int	ft_update()
//{
	
//}

int	ft_found_player_y(t_map map_p, const char *map_model)
{
	int	i;
	int	j;
	int	y;

	y = 0;
	i = 0;
	while (i < ft_count_rows(map_model))
	{
		j = 0;
		while (j < ft_strlen(map_p.map[0]))
		{
			if (map_p.map[i][j] == 'P')
			{
				ft_printf("X trovata: %d\n", j);
				y = j;
			}
			j++;
		}
		i++;
	}
	ft_printf("Sprite position Y: %d\n", y);
	return (y);
}

int	ft_found_player_x(t_map map_p, const char *map_model)
{
	int	i;
	int	j;
	int	x;

	//ft_printf("PATH: %s\n", map_model);
	//ft_printf("ROWS: %d\n", ft_count_rows(map_model));
	//ft_printf("COLS: %d\n", ft_strlen(map_p.map[0]));
	i = 0;
	while (i < ft_count_rows(map_model))
	{
		j = 0;
		while (j < ft_strlen(map_p.map[0]) - 1)
		{
			if (map_p.map[i][j] == 'P')
			{
				ft_printf("X trovata: %d\n", i);
				x = i;
			}
			j++;
		}
		i++;
	}
	ft_printf("Sprite position X: %d\n", x);
	return (x);
}

int	ft_input(int key, t_program *program_ref, t_map map_p, const char *map_model)
{
	t_program	*program;

	program = program_ref;
	ft_printf("PATH1: %s\n", map_model); //CHECKPOINT: non viene caricato il percorso della mappa!
	ft_found_player_x(map_p, map_model);
	//ft_found_player_y(map_p, map_model);
	/*mlx_clear_window(program->mlx, program->window.pointer);

	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;

	mlx_put_image_to_window(program->mlx, program->window.pointer, program->sprite.pointer, program->sprite_position.x, program->sprite_position.y);*/
	ft_printf("Key pressed: %d\n", key);
	return (0);
}