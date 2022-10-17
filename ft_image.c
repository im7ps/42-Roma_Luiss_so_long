/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:55:03 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/17 17:57:35 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image		ft_new_sprite(void *mlx, char img)
{
	t_image		image;
	char		*path;

	path = NULL;
	if (img == '0')
	{
		path = "/Users/sgerace/Desktop/42student/so_long/images/grass.xpm";
	}
	else if (img == '1')
	{
		path = "/Users/sgerace/Desktop/42student/so_long/images/wall.xpm";
	}
	else if (img == 'C')
	{
		path = "/Users/sgerace/Desktop/42student/so_long/images/collectible.xpm";
	}
	else if (img == 'P')
	{
		path = "/Users/sgerace/Desktop/42student/so_long/images/player.xpm";
	}
	else if (img == 'E')
	{
		path = "/Users/sgerace/Desktop/42student/so_long/images/exit.xpm";
	}
	else if (img == 'D')
	{
		path = "/Users/sgerace/Desktop/42student/so_long/images/danger.xpm";
	}
	image.pointer = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	image.pixels = mlx_get_data_addr(image.pointer, &image.bits_per_pixel, &image.line_size, &image.endian);
	return (image);
}