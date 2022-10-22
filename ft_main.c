/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:17:47 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/22 22:35:49 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_p		p;

	if (argc != 2)
		return (1);
	if (upload_map(&p.map_p, argv[1]) == 1)
	{
		ft_printf("Caricamento mappa fallito\n");
		return (1);
	}
	//p.mlx = mlx_init();
	//p.window = ft_init_window(p.mlx, p.map_p, argv[1], "Ice Cube");
	//p.element = (t_element *) malloc (sizeof(t_element) * 6);
	//ft_load_textures(&p, p.map_p, argv[1]);
	//mlx_key_hook(p.window.ptr, *ft_input, &p);
	//mlx_loop(p.mlx);
	int i = 0;
	while (i < ft_count_cols(argv[1]))
	{
		free(p.map_p.map[i]);
		p.map_p.map[i] = NULL;
		i++;
	}
	free(p.map_p.map);
	p.map_p.map = NULL;
	return (0);
}
