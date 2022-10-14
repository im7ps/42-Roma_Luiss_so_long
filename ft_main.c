/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:17:47 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/14 15:32:31 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	s_map		*map_ptr;
	t_program	program;

	program.mlx = mlx_init();

	program.window = ft_init_window(program.mlx, 1920, 1080, "Ice Cube");

	program.sprite = ft_new_sprite(program.mlx, "/Users/sgerace/Desktop/42student/so_long/images/one_piece_img.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;

	mlx_put_image_to_window(program.mlx, program.window.pointer, program.sprite.pointer, program.sprite.size.x, program.sprite.size.y);

	mlx_key_hook(program.window.pointer, *ft_input, &program);
	//mlx_loop_hook(program.mlx, *ft_update, &program);

	map_ptr = (s_map *) malloc (sizeof(s_map)); //mappa da allocare meglio
	map_ptr->map = upload_map(map_ptr);
	if(check_map_errors(map_ptr) == 1)
		ft_printf("Error\n");
	else
		ft_printf("Valid\n");
	mlx_loop(program.mlx);
}
