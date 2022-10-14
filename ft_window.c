/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:47:42 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/14 13:47:58 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_w()
{
	exit(0);
}

t_window ft_init_window(void *mlx, int width, int height, char *title)
{
	t_window	window;

	window.pointer = mlx_new_window(mlx, width, height, title);
	window.size.x = width;
	window.size.y = height;

	mlx_hook(window.pointer, 17, 0, ft_close_w, 0);
	return (window);	
}
