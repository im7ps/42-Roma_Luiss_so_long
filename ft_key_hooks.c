/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/18 18:49:59 by sgerace          ###   ########.fr       */
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

int	ft_input(int key, t_program *program)
{
	//mlx_clear_window(program->mlx, program->window.pointer);
	program->floor.position.x = program->player.position.x;
	program->floor.position.y = program->player.position.y;
	//mlx_destroy_image(program->mlx, program->player.sprite.pointer);
	mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->floor.position.x, program->floor.position.y);


	if (key == 2) //destra
		program->player.position.x += 128;
	else if (key == 0) //sinistra
		program->player.position.x -= 128;
	else if (key == 1) //giú
		program->player.position.y += 128;
	else if (key == 13) //su
		program->player.position.y -= 128;
		
	
	mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
	ft_printf("Key pressed: %d\n", key);
	return (0);
}