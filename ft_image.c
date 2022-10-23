/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:55:03 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/23 22:59:04 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_load_path(void)
{
	char	**i_p;
	int		i;

	i = 0;
	i_p = (char **) malloc (sizeof (char *) * 7);
	i_p[0] = "/Users/sgerace/Desktop/42student/so_long/images/collectible.xpm";
	i_p[1] = "/Users/sgerace/Desktop/42student/so_long/images/danger.xpm";
	i_p[2] = "/Users/sgerace/Desktop/42student/so_long/images/exit.xpm";
	i_p[3] = "/Users/sgerace/Desktop/42student/so_long/images/grass.xpm";
	i_p[4] = "/Users/sgerace/Desktop/42student/so_long/images/player.xpm";
	i_p[5] = "/Users/sgerace/Desktop/42student/so_long/images/wall.xpm";
	i_p[6] = "/Users/sgerace/Desktop/42student/so_long/images/exit_success.xpm";
	return (i_p);
}

void	**ft_load_img(void	*mlx, t_image image)
{
	char	**i_p;
	void	**img_array;

	i_p = ft_load_path();
	img_array = (void **) malloc(sizeof(void *) * 7);
	img_array[0] = mlx_xpm_file_to_image(mlx, i_p[0], \
		&image.size.x, &image.size.y);
	img_array[1] = mlx_xpm_file_to_image(mlx, i_p[1], \
		&image.size.x, &image.size.y);
	img_array[2] = mlx_xpm_file_to_image(mlx, i_p[2], \
		&image.size.x, &image.size.y);
	img_array[3] = mlx_xpm_file_to_image(mlx, i_p[3], \
		&image.size.x, &image.size.y);
	img_array[4] = mlx_xpm_file_to_image(mlx, i_p[4], \
		&image.size.x, &image.size.y);
	img_array[5] = mlx_xpm_file_to_image(mlx, i_p[5], \
		&image.size.x, &image.size.y);
	img_array[6] = mlx_xpm_file_to_image(mlx, i_p[6], \
		&image.size.x, &image.size.y);
	free(i_p);
	return (img_array);
}

t_image	ft_new_sprite(void *mlx, char img)
{
	t_image	image;

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
	free(image.img_array);
	return (image);
}
