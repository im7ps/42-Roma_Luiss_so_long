/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/20 20:31:32 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, t_program *program)
{
	int	x;
	int	y;

	x = program->player.position.x / 128; //COLONNE
	y = program->player.position.y / 128; //RIGHE
	if (key == 2) //destra
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		if (program->map_p.map[y][x + 1] == '1')
		{
			return(1);
		}
		if (program->map_p.map[y][x + 1] == 'E')
		{
			if (program->map_p.c == -1)
			{
				mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
				ft_printf("End Game, ggwp!\n");
			}
		}
		else if (program->map_p.map[y][x + 1] == 'C')
		{
			
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y][x + 1] = '0';
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
	}
	else if (key == 0) //sinistra
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		if (program->map_p.map[y][x - 1] == '1')
		{

		}
		else if (program->map_p.map[y][x - 1] == 'E')
		{
			if (program->map_p.c == -1)
			{
				mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
				ft_printf("End Game, ggwp!\n");
			}
		}
		else if (program->map_p.map[y][x - 1] == 'C')
		{
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y][x - 1] = '0';
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
	}
	else if (key == 1) //giú
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		if (program->map_p.map[y + 1][x] == '1')
		{

		}
		else if (program->map_p.map[y + 1][x] == 'E')
		{
			if (program->map_p.c == -1)
			{
				mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
				ft_printf("End Game, ggwp!\n");
			}
		}
		else if (program->map_p.map[y + 1][x] == 'C')
		{
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y + 1][x] = '0';
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
	}
	else if (key == 13) //su
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		if (program->map_p.map[y - 1][x] == '1')
		{
		}
		else if (program->map_p.map[y - 1][x] == 'E')
		{
			if (program->map_p.c == -1)
			{
				mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
				program->player.position.x -= 128;
				
				ft_printf("End Game, ggwp!\n");
			}
		}
		else if (program->map_p.map[y - 1][x] == 'C')
		{
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y - 1][x] = '0';
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
	}
	if (program->map_p.c == -1)
	{
		program->success.sprite = ft_new_sprite(program->mlx, 'S');
		mlx_put_image_to_window(program->mlx, program->window.pointer, program->success.sprite.pointer, program->exit.position.x, program->exit.position.y);
	}
	return (0);
}