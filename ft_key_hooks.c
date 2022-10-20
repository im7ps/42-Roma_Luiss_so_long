/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/20 19:27:05 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int	ft_update()
//{
	
//}

int	ft_input(int key, t_program *program)
{
	int	x;
	int	y;

	x = program->player.position.x / 128; //COLONNE
	y = program->player.position.y / 128; //RIGHE
	//mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->floor.position.x, program->floor.position.y);
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
				program->player.position.x += 128;
				mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
				ft_printf("End Game, ggwp!\n");
			}
			else
			{
				ft_printf("Pigghia i sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
			}
		}
		else if (program->map_p.map[y][x + 1] == 'C')
		{
			
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y][x + 1] = '0';
			ft_printf("Hai preso un sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
			ft_printf("Casella: %c\n", program->map_p.map[y][x]);
		}
	}
	else if (key == 0) //sinistra
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		ft_printf("Casella a sinistra: %c\n", program->map_p.map[y][x - 1]);
		if (program->map_p.map[y][x - 1] == '1')
		{
			ft_printf("Murooooooo\n");
		}
		else if (program->map_p.map[y][x - 1] == 'E')
		{
			if (program->map_p.c == -1)
			{
				program->player.position.x -= 128;
				ft_printf("End Game, ggwp!\n");
			}
			else
				ft_printf("Pigghia i sordi, ti mancano ancora %d dogecoin per vincere!\n", program->map_p.c);
		}
		else if (program->map_p.map[y][x - 1] == 'C')
		{
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y][x - 1] = '0';
			ft_printf("Hai preso un sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.x -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
			ft_printf("Casella: %c\n", program->map_p.map[y][x]);
		}
	}
	else if (key == 1) //giú
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		ft_printf("Casella giú: %c\n", program->map_p.map[y + 1][x]);
		if (program->map_p.map[y + 1][x] == '1')
		{
			ft_printf("Murooooooo\n");
		}
		else if (program->map_p.map[y + 1][x] == 'E')
		{
			if (program->map_p.c == -1)
			{
				program->player.position.y += 128;
				ft_printf("End Game, ggwp!\n");
			}
			else
				ft_printf("Pigghia i sordi, ti mancano ancora %d dogecoin per vincere!\n", program->map_p.c);
		}
		else if (program->map_p.map[y + 1][x] == 'C')
		{
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y + 1][x] = '0';
			ft_printf("Hai preso un sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y += 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
			ft_printf("Casella: %c\n", program->map_p.map[y][x]);
		}
	}
	else if (key == 13) //su
	{
		x = program->player.position.x / 128;
		y = program->player.position.y / 128;
		ft_printf("Casella su: %c\n", program->map_p.map[y - 1][x]);
		if (program->map_p.map[y - 1][x] == '1')
		{
			ft_printf("Murooooooo\n");
		}
		else if (program->map_p.map[y - 1][x] == 'E')
		{
			if (program->map_p.c == -1)
			{
				mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
				program->player.position.x -= 128;
				
				ft_printf("End Game, ggwp!\n");
			}
			else
				ft_printf("Pigghia i sordi, ti mancano ancora %d dogecoin per vincere!\n", program->map_p.c);
		}
		else if (program->map_p.map[y - 1][x] == 'C')
		{
			program->map_p.c = program->map_p.c - 1;
			program->map_p.map[y - 1][x] = '0';
			ft_printf("Hai preso un sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->player.position.x, program->player.position.y);
			program->player.position.y -= 128;
			mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
			ft_printf("Casella: %c\n", program->map_p.map[y][x]);
		}
	}
	return (0);
}