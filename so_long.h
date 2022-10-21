/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:19:46 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/21 20:32:48 by sgerace          ###   ########.fr       */
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
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;
/* A ptr to the window and its size */
typedef struct s_window {
	void		*ptr;
	t_vector	size;
}				t_window;

/* all info needed for an image */
typedef struct s_image {
	void		*ptr;
	void		**img_array;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_floor {
	t_vector	pos;
	t_image		sprite;
}				t_floor;

typedef struct s_coin {
	t_vector	pos;
	t_image		sprite;
}				t_coin;

typedef struct s_player {
	t_vector	pos;
	t_image		sprite;
}				t_player;

typedef struct s_success {
	t_vector	pos;
	t_image		sprite;
}				t_success;

typedef struct s_exit {
	t_vector	pos;
	t_image		sprite;
}				t_exit;

typedef struct s_wall {
	t_vector	pos;
	t_image		sprite;
}				t_wall;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		e;
	int		p;
	int		c;
}	t_map;

typedef struct s_p {
	void		*mlx;
	t_window	window;
	t_map		map_p;
	t_image		sprite;
	t_vector	sprite_pos;
	//t_elemts	elem[6]; //DA FARE: un array con tutte le strutture degli elementi presenti nel gioco
	t_player	player;
	t_floor		floor;
	t_coin		coin;
	t_success	success;
	t_exit		exit;
	t_wall		wall;
}				t_p;

t_window	ft_init_window(void *mlx, t_map map_p, char *m_model, char *title);
t_image		ft_new_sprite(void *mlx, char img);
int			ft_close_w(void);
int			ft_input(int key, t_p *p);
int			ft_count_rows(const char *map_model);
char		ft_find_last(t_map *map_ptr, const char *map_model);
void		ft_load_textures(t_p *p, t_map map_p, const char *map_model);
int			check_map_errors(t_map *map_ptr, const char *map_model);
int			upload_map(t_map *map_ptr, const char *map_model);
int			rectangle_checker(t_map *map_ptr, const char *map_model);
int			walls_checker(t_map *map_ptr, const char *map_model);
int			empty_or_invalid_checker(t_map *map_ptr, const char *map_model);
int			items_checker(t_map *map_ptr, const char *map_model);
void		moves_counter(void	*mlx_ptr, void	*win_ptr);
int			items_counter(char c);

#endif
