/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:47:42 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/21 20:07:03 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_w(void)
{
	exit(0);
}

t_window	ft_init_window(void *mlx, t_map map_p, char *map_model, char *title)
{
	t_window	window;
	int			width;
	int			height;

	height = ft_count_rows(map_model);
	width = ft_strlen(map_p.map[0]) - 1;
	window.ptr = mlx_new_window(mlx, width * 128, height * 128, title);
	window.size.x = width * 128;
	window.size.y = height * 128;
	mlx_hook(window.ptr, 17, 0, ft_close_w, 0);
	return (window);
}
