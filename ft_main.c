/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:17:47 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/22 16:51:19 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//t_map	*ft_map_allocation(t_map *map_ptr, char *path)
//{
//	int	fd;

//	map_ptr->rows = ft_count_rows(path);
//	fd = open(path, O_RDONLY);
//	if (fd == -1)
//	{
//		ft_printf("Errore in upload map\n");
//		map_ptr = NULL;
//		return (map_ptr);
//	}
//	map_ptr->map = (char **) malloc (sizeof(char *) * (map_ptr->rows + 1));
//	return (map_ptr);
//}

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
	//int i = 0;
	//while (i < ft_count_rows(argv[1]))
	//{
	//	free(p.map_p.map[i]);
	//	i++;
	//}
	//free(&p.map_p);
	return (0);
}
