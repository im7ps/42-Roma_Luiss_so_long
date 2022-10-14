/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/14 15:30:10 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int	ft_update()
//{
	
//}

int	ft_input(int key, t_program *program_ref)
{
	t_program *program;

	program = program_ref;
	mlx_clear_window(program->mlx, program->window.pointer);
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;

	mlx_put_image_to_window(program->mlx, program->window.pointer, program->sprite.pointer, program->sprite_position.x, program->sprite_position.y);
	ft_printf("Key pressed: %d\n", key);
	return (0);
}