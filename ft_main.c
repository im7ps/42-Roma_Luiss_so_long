/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:17:47 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/17 20:38:54 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		map_p;
	t_program	program;

	if (argc != 2)
		return (1);

	if (upload_map(&map_p, argv[1]) == 1)
	{
		ft_printf("Caricamento mappa fallito\n");
		return (1);
	}
	program.mlx = mlx_init();
	program.window = ft_init_window(program.mlx, map_p, argv[1], "Ice Cube");
	ft_load_textures(program, map_p, argv[1]);

	mlx_key_hook(program.window.pointer, *ft_input, &program);
	//mlx_loop_hook(program.mlx, *ft_update, &program);

	mlx_loop(program.mlx);
	return (0);
}
