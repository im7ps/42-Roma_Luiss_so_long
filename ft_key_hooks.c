/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/24 17:54:48 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_score(t_p *p)
{
	static int	score;
	char		*score_s;

	score++;
	score_s = ft_itoa(score);
	mlx_put_image_to_window(p->mlx, p->window.ptr, \
		p->e[4].sprite.ptr, 128, 0);
	mlx_string_put(p->mlx, p->window.ptr, 130, 15, 0xFF0000, score_s);
	free(score_s);
}

void	ft_handle_coin(t_p *p, int s_value, char dir, int d_value)
{
	int	x;
	int	y;

	x = p->e[0].pos.x / 128;
	y = p->e[0].pos.y / 128;
	p->map_p.c = p->map_p.c - 1;
	mlx_put_image_to_window(p->mlx, p->window.ptr, p->e[1].sprite.ptr, \
		p->e[0].pos.x, p->e[0].pos.y);
	if (dir == 'R' || dir == 'L')
		ft_horizontal_mov(p, d_value, s_value);
	else if (dir == 'U' || dir == 'D')
		ft_vertical_mov(p, d_value, s_value);
	mlx_put_image_to_window(p->mlx, p->window.ptr, p->e[0].sprite.ptr, \
		p->e[0].pos.x, p->e[0].pos.y);
	if (p->map_p.c == 0)
	{
		p->e[5].sprite = ft_new_sprite(p->mlx, 'S');
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->e[5].sprite.ptr, \
			p->e[3].pos.x, p->e[3].pos.y);
	}
	ft_update_score(p);
}

void	ft_handle_exit(t_p *p, int key)
{
	if (p->map_p.c == 0)
	{
		ft_update_score(p);
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->e[1].sprite.ptr, \
			p->e[0].pos.x, p->e[0].pos.y);
		mlx_clear_window(p->mlx, p->window.ptr);
		mlx_destroy_window(p->mlx, p->window.ptr);
		ft_free_stuff(p);
		exit(0);
	}
	else if (key == 53)
	{
		mlx_destroy_window(p->mlx, p->window.ptr);
		ft_free_stuff(p);
		exit(0);
	}
}

int	ft_input(int key, t_p *p)
{
	int	x;
	int	y;

	x = p->e[0].pos.x / 128;
	y = p->e[0].pos.y / 128;
	mlx_string_put(p->mlx, p->window.ptr, 15, 15, 0xFF0000, "SCORE:");
	if (key == 2)
		ft_go_right(p, x, y);
	else if (key == 0)
		ft_go_left(p, x, y);
	else if (key == 1)
		ft_go_down(p, x, y);
	else if (key == 13)
		ft_go_up(p, x, y);
	else if (key == 53)
	{
		ft_handle_exit(p, key);
	}
	return (0);
}
