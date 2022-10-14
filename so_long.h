/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:19:46 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/14 15:22:59 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"
# include "mlx.h"

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*pointer;
	t_vector	size;
}				t_window;

/* all info needed for an image */
typedef struct	s_image {
	void		*pointer;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		e;
	int		p;
	int		c;
}   s_map;

t_window	ft_init_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
int			ft_input(int key, t_program *program);

char	**upload_map(s_map  *map_ptr);
void	moves_counter(void	*mlx_ptr, void	*win_ptr);
int		check_map_errors(s_map  *map_ptr);
int		rectangle_checker(s_map  *map_ptr);
char	find_last(s_map  *map_ptr);
int		walls_checker(s_map *map_ptr);
int		empty_or_invalid_checker(s_map  *map_ptr);
int		items_checker(s_map *map_ptr);
int		items_counter(char c);
int		count_rows(void);

//void		*initialize_window(void	*mlx_ptr);
//void		*initialize_pointer();

#endif
