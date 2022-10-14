/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:55:03 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/14 14:45:09 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image		ft_new_sprite(void *mlx, char *path)
{
	t_image		image;

	image.pointer = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	image.pixels = mlx_get_data_addr(image.pointer, &image.bits_per_pixel, &image.line_size, &image.endian);
	return (image);
}