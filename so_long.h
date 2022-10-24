/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:19:46 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/24 16:43:08 by sgerace          ###   ########.fr       */
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
typedef struct s_vector {
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

typedef struct s_e {
	t_vector	pos;
	t_image		sprite;
}				t_e;

typedef struct s_map {
	char	**map;
	int		rows;
	int		cols;
	int		e;
	int		p;
	int		c;
	int		f;
}	t_map;

typedef struct s_p {
	void		*mlx;
	t_window	window;
	t_map		map_p;
	t_image		sprite;
	t_vector	sprite_pos;
	t_e			*e;
}				t_p;

t_window	ft_init_window(void *mlx, t_map map_p, char *m_model, char *title);
t_image		ft_new_sprite(void *mlx, char img);
int			ft_close_w(void);

void		ft_go_right(t_p *p, int x, int y);
void		ft_go_left(t_p *p, int x, int y);
void		ft_go_up(t_p *p, int x, int y);
void		ft_go_down(t_p *p, int x, int y);

int			ft_input(int key, t_p *p);
int			ft_count_rows(const char *map_model);
char		ft_find_last(t_map *map_ptr, const char *map_model);
void		ft_load_textures(t_p *p, t_map map_p, const char *map_model);
void		ft_load_wall(t_p *p);
void		ft_load_exit(t_p *p, int i, int j);
void		ft_load_coin(t_p *p);
void		ft_load_floor(t_p *p);
void		ft_load_player(t_p *p, int i, int j);
int			ft_count_cols(const char *map_model);
void		ft_free_stuff(t_p *p);

void		ft_handle_exit(t_p *p, int key);
void		ft_handle_coin(t_p *p, int s_value, char dir, int d_value);
void		ft_simple_movement(t_p *p, char dir, int d_value);
void		ft_vertical_mov(t_p *p, int d_value, int s_value);
void		ft_horizontal_mov(t_p *p, int d_value, int s_value);
void		ft_update_score(t_p *p);

int			check_map_errors(t_map *map_ptr, const char *map_model);
int			upload_map(t_map *map_ptr, const char *map_model);
int			rectangle_checker(t_map *map_ptr, const char *map_model);
int			walls_checker(t_map *map_ptr, const char *map_model);
int			empty_or_invalid_checker(t_map *map_ptr, const char *map_model);
int			items_checker(t_map *map_ptr, const char *map_model);
int			items_counter(char c);

#endif
