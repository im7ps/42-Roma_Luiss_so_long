/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:17:47 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/23 22:48:13 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_stuff(t_p *p)
{
	int	i;

	i = 0;
	while (p->map_p.map[i] != NULL && i < p->map_p.rows)
	{
		free(p->map_p.map[i]);
		p->map_p.map[i] = NULL;
		i++;
	}
	free(p->map_p.map);
	p->map_p.map = NULL;
}

int	main(int argc, char **argv)
{
	t_p		p;

	if (argc != 2)
		return (1);
	if (upload_map(&p.map_p, argv[1]) == 1)
	{
		ft_free_stuff(&p);
		ft_printf("Caricamento mappa fallito\n");
		return (1);
	}
	p.mlx = mlx_init();
	p.window = ft_init_window(p.mlx, p.map_p, argv[1], "Ice Cube");
	p.e = (t_e *) malloc (sizeof(t_e) * 6);
	ft_load_textures(&p, p.map_p, argv[1]);
	mlx_key_hook(p.window.ptr, *ft_input, &p);
	mlx_loop(p.mlx);
	return (0);
}
