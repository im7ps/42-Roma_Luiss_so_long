/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:55:03 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/21 20:05:28 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_load_path(void)
{
	char	**img_path;
	int		i;

	i = 0;
	img_path = (char **) malloc (sizeof (char *) * 7);
	img_path[0] = "/Users/sgerace/Desktop/42student/so_long/images/collectible.xpm";
	img_path[1] = "/Users/sgerace/Desktop/42student/so_long/images/danger.xpm";
	img_path[2] = "/Users/sgerace/Desktop/42student/so_long/images/exit.xpm";
	img_path[3] = "/Users/sgerace/Desktop/42student/so_long/images/grass.xpm";
	img_path[4] = "/Users/sgerace/Desktop/42student/so_long/images/player.xpm";
	img_path[5] = "/Users/sgerace/Desktop/42student/so_long/images/wall.xpm";
	img_path[6] = "/Users/sgerace/Desktop/42student/so_long/images/exit_success.xpm";
	return (img_path);
}

void	**ft_load_img(void	*mlx, t_image image)
{
	char	**img_path;
	void	**img_array;

	img_path = ft_load_path();
	img_array = (void **) malloc(sizeof(void *) * 7);
	img_array[0] = mlx_xpm_file_to_image(mlx, img_path[0], &image.size.x, &image.size.y);
	img_array[1] = mlx_xpm_file_to_image(mlx, img_path[1], &image.size.x, &image.size.y);
	img_array[2] = mlx_xpm_file_to_image(mlx, img_path[2], &image.size.x, &image.size.y);
	img_array[3] = mlx_xpm_file_to_image(mlx, img_path[3], &image.size.x, &image.size.y);
	img_array[4] = mlx_xpm_file_to_image(mlx, img_path[4], &image.size.x, &image.size.y);
	img_array[5] = mlx_xpm_file_to_image(mlx, img_path[5], &image.size.x, &image.size.y);
	img_array[6] = mlx_xpm_file_to_image(mlx, img_path[6], &image.size.x, &image.size.y);
	return (img_array);
}

t_image	ft_new_sprite(void *mlx, char img)
{
	char	**img_path;
	t_image	image;

	img_path = ft_load_path();
	image.img_array = NULL;
	image.img_array = ft_load_img(mlx, image);
	if (img == '0')
		image.ptr = image.img_array[3];
	else if (img == '1')
		image.ptr = image.img_array[5];
	else if (img == 'C')
		image.ptr = image.img_array[0];
	else if (img == 'P')
		image.ptr = image.img_array[4];
	else if (img == 'E')
		image.ptr = image.img_array[2];
	else if (img == 'D')
		image.ptr = image.img_array[1];
	else if (img == 'S')
		image.ptr = image.img_array[6];
	image.pixels = mlx_get_data_addr(image.ptr, &image.bits_per_pixel, &image.line_size, &image.endian);
	return (image);
}
