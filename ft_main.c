/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:17:47 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/21 20:06:18 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_p	p;

	if (argc != 2)
		return (1);
	if (upload_map(&p.map_p, argv[1]) == 1)
	{
		ft_printf("Caricamento mappa fallito\n");
		return (1);
	}
	p.mlx = mlx_init();
	p.window = ft_init_window(p.mlx, p.map_p, argv[1], "Ice Cube");
	ft_load_textures(&p, p.map_p, argv[1]);
	mlx_key_hook(p.window.ptr, *ft_input, &p);
	//mlx_loop_hook(p.mlx, *ft_update, &p);
	mlx_loop(p.mlx);
	return (0);
}
