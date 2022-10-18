/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:19:46 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/18 18:44:25 by sgerace          ###   ########.fr       */
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
	void		**img_array;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_floor {
	t_vector	position;
	t_image		sprite;
}				t_floor;

typedef struct	s_coin {
	t_vector	position;
	t_image		sprite;
}				t_coin;

typedef struct	s_player {
	t_vector	position;
	t_image		sprite;
}				t_player;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	t_player	player;
	t_floor		floor;
	t_coin		coin;
}				t_program;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		e;
	int		p;
	int		c;
}	t_map;

/*t_window	ft_init_window(void *mlx, int widht, int height, char *name); SAMPLE*/ 
t_window	ft_init_window(void *mlx, t_map map_p, char *map_model, char *title);
t_image		ft_new_sprite(void *mlx, char img);
int			ft_input(int key, t_program *program);
int			check_map_errors(t_map  *map_ptr, const char *map_model);
int			upload_map(t_map  *map_ptr, const char *map_model);
int			rectangle_checker(t_map  *map_ptr, const char *map_model);
int			walls_checker(t_map *map_ptr, const char *map_model);
int			empty_or_invalid_checker(t_map  *map_ptr, const char *map_model);
int			items_checker(t_map *map_ptr, const char *map_model);
int			ft_count_rows(const char *map_model);
char		ft_find_last(t_map  *map_ptr, const char *map_model);
void		ft_load_textures(t_program *program, t_map  map_p, const char *map_model);
void		moves_counter(void	*mlx_ptr, void	*win_ptr);
int			items_counter(char c);


#endif
