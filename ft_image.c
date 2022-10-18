/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:55:03 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/18 18:26:53 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_load_path()
{
	char	**img_path;
	int		i;

	i = 0;
	img_path = (char **) malloc(sizeof(char*) * 6);
	img_path[0] = "/Users/sgerace/42-Roma_Luiss_so_long/images/collectible.xpm";
	img_path[1] = "/Users/sgerace/42-Roma_Luiss_so_long/images/danger.xpm";
	img_path[2] = "/Users/sgerace/42-Roma_Luiss_so_long/images/exit.xpm";
	img_path[3] = "/Users/sgerace/42-Roma_Luiss_so_long/images/grass.xpm";
	img_path[4] = "/Users/sgerace/42-Roma_Luiss_so_long/images/player.xpm";
	img_path[5] = "/Users/sgerace/42-Roma_Luiss_so_long/images/wall.xpm";
	return (img_path);
}

void	**ft_load_img(void	*mlx, t_image image)
{
	char	**img_path;
	void	**img_array;

	img_path = ft_load_path();
	img_array = (void **) malloc(sizeof(void*) * 6);
	img_array[0] = mlx_xpm_file_to_image(mlx, img_path[0], &image.size.x, &image.size.y);
	img_array[1] = mlx_xpm_file_to_image(mlx, img_path[1], &image.size.x, &image.size.y);
	img_array[2] = mlx_xpm_file_to_image(mlx, img_path[2], &image.size.x, &image.size.y);
	img_array[3] = mlx_xpm_file_to_image(mlx, img_path[3], &image.size.x, &image.size.y);
	img_array[4] = mlx_xpm_file_to_image(mlx, img_path[4], &image.size.x, &image.size.y);
	img_array[5] = mlx_xpm_file_to_image(mlx, img_path[5], &image.size.x, &image.size.y);
	return (img_array);
}

t_image		ft_new_sprite(void *mlx, char img)
{
	char	**img_path;
	t_image image;

	img_path = ft_load_path();
	image.img_array = NULL;
	image.img_array = ft_load_img(mlx, image);
	if (img == '0')
	{
		image.pointer = image.img_array[3];
	}
	else if (img == '1')
	{
		image.pointer = image.img_array[5];
	}
	else if (img == 'C')
	{
		image.pointer = image.img_array[0];
	}
	else if (img == 'P')
	{
		image.pointer = image.img_array[4];
	}
	else if (img == 'E')
	{
		image.pointer = image.img_array[2];
	}
	else if (img == 'D')
	{
		image.pointer = image.img_array[1];
	}
	image.pixels = mlx_get_data_addr(image.pointer, &image.bits_per_pixel, &image.line_size, &image.endian);
	return (image);
}