/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/20 13:29:16 by sgerace          ###   ########.fr       */
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

	x = program->player.position.x / 128;
	y = program->player.position.y / 128;
	//ft_printf("Ei tu in %d %d Va pigghia i sordi!\n", program->player.position.x / 128, program->player.position.y / 128);
	//program->floor.position.x = program->player.position.x;
	//program->floor.position.y = program->player.position.y;
	//mlx_put_image_to_window(program->mlx, program->window.pointer, program->floor.sprite.pointer, program->floor.position.x, program->floor.position.y);
	//if (key == 2) //destra
	//{
		//x = program->player.position.y / 128;
		//y = program->player.position.x / 128;
		//ft_printf("Pos: %d %d\n", x, y);
		//if (program->map_p.map[x + 1][y] == '1')
		//{
		//	ft_printf("Murooooooo\n");
		//}
		//else
		//{
		//	program->player.position.x += 128;
		//	mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		//}
		//else if (program->map_p.map[x + 1][y] == 'E')
		//{
		//	if (program->map_p.c == 0)
		//	{
		//		program->player.position.x += 128;
		//		mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		//		ft_printf("End Game, ggwp!\n");
		//	}
		//	else
		//	{
		//		program->player.position.x += 128;
		//		mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		//		ft_printf("Pigghia i sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
		//	}
		//}
		//else if (program->map_p.map[x + 1][y] == 'C')
		//{
		//	program->map_p.c = program->map_p.c - 1;
		//	program->map_p.map[x + 1][y] = '0';
		//	ft_printf("Hai preso un sordi, ti mancano ancora %d dogecoin!\n", program->map_p.c);
		//	program->player.position.x += 128;
		//	mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		//}
		//else if (program->map_p.map[x + 1][y] == '0')
		//{
		//	program->player.position.x += 128;
		//	mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		//}
	//}
	//else if (key == 0) //sinistra
	//{
		//if (program->map_p.map[x][y - 1] == '1')
		//{
		//	ft_printf("Murooooooo\n");
		//}
		//else if (program->map_p.map[x][y - 1] == 'E')
		//{
		//	if (program->map_p.c == 0)
		//	{
				//program->player.position.x -= 128;
		//		ft_printf("End Game, ggwp!\n");
		//	}
		//	else
		//		ft_printf("Pigghia i sordi, ti mancano ancora %d dogecoin per vincere!\n", program->map_p.c);
		//}
		//else if (program->map_p.map[x][y - 1] == 'C')
		//{
		//	program->map_p.c = program->map_p.c - 1;
		//	program->map_p.map[x][y - 1] = '0';
			//mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
		//}
			//program->player.position.x += 128;
	//}
	//	program->player.position.x -= 128;
	//else if (key == 1) //giú
	//{
	//	ft_printf("Key: %d\n", key);
	//	program->player.position.y += 128;
	//	mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
	//}
	//	program->player.position.y += 128;
	//else if (key == 13) //su
	//{
	//	ft_printf("Key: %d\n", key);
	//	program->player.position.y -= 128;
	//	mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
	//}
	//	program->player.position.y -= 128;
	//mlx_put_image_to_window(program->mlx, program->window.pointer, program->player.sprite.pointer, program->player.position.x, program->player.position.y);
	//ft_printf("Key pressed: %d\n", key);
	return (0);
}