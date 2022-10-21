/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:09 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/21 20:52:14 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_score(t_p *p)
{
	static int score;

	score++;
	mlx_put_image_to_window(p->mlx, p->window.ptr, p->wall.sprite.ptr, 128, 0);
	mlx_string_put(p->mlx, p->window.ptr, 130, 15, 0xFF0000, ft_itoa(score));
}

void	ft_simple_movement(t_p *p, char dir, int d_value)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr, \
		p->floor.sprite.ptr, p->player.pos.x, p->player.pos.y);
	if (dir == 'L' || dir == 'R')
	{
		p->player.pos.x += d_value;
	}
	else if (dir == 'U' || dir == 'D')
	{
		p->player.pos.y += d_value;
	}
	mlx_put_image_to_window(p->mlx, p->window.ptr, \
		p->player.sprite.ptr, p->player.pos.x, p->player.pos.y);
	ft_update_score(p);
}

void	ft_handle_coin(t_p *p, int s_value, char dir, int d_value)
{
	int	x;
	int	y;

	x = p->player.pos.x / 128;
	y = p->player.pos.y / 128;
	p->map_p.c = p->map_p.c - 1;
	mlx_put_image_to_window(p->mlx, p->window.ptr, p->floor.sprite.ptr, p->player.pos.x, p->player.pos.y);
	if (dir == 'R' || dir == 'L')
	{
		p->map_p.map[y][x + d_value] = '0';
		p->player.pos.x += s_value;
	}
	else if (dir == 'U' || dir == 'D')
	{
		p->map_p.map[y + d_value][x] = '0';
		p->player.pos.y += s_value;
	}
	mlx_put_image_to_window(p->mlx, p->window.ptr, p->player.sprite.ptr, p->player.pos.x, p->player.pos.y);
	ft_update_score(p);
}

void	ft_handle_exit(t_p *p, int key)
{
	if (p->map_p.c == 0)
	{
		ft_update_score(p);
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->floor.sprite.ptr, p->player.pos.x, p->player.pos.y);
		mlx_clear_window(p->mlx, p->window.ptr);
		mlx_destroy_window(p->mlx, p->window.ptr);
		exit(0);
	}
	else if (key == 53)
	{
		mlx_destroy_window(p->mlx, p->window.ptr);
		exit(0);
	}
}

void	ft_go_right(t_p *p, int x, int y)
{
	p->map_p.map[y][x] = '0';
	if (p->map_p.map[y][x + 1] == '0')
	{
		ft_simple_movement(p, 'R', 128);
	}
	else if (p->map_p.map[y][x + 1] == 'E')
	{
		ft_handle_exit(p, 0);
	}
	else if (p->map_p.map[y][x + 1] == 'C')
	{
		ft_handle_coin(p, 128, 'R', 1);
	}
	else if (p->map_p.map[y][x + 1] == 'D')
	{
		mlx_destroy_window(p->mlx, p->window.ptr);
		exit(0);
	}
	if (p->map_p.c == 0)
	{
		p->success.sprite = ft_new_sprite(p->mlx, 'S');
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->success.sprite.ptr, \
			p->exit.pos.x, p->exit.pos.y);
	}
}

void	ft_go_left(t_p *p, int x, int y)
{
	p->map_p.map[y][x] = '0';
	if (p->map_p.map[y][x - 1] == '0')
	{
		ft_simple_movement(p, 'L', -128);
	}
	else if (p->map_p.map[y][x - 1] == 'E')
	{
		ft_handle_exit(p, 0);
	}
	else if (p->map_p.map[y][x - 1] == 'C')
	{
		ft_handle_coin(p, -128, 'L', -1);
	}
	else if (p->map_p.map[y][x - 1] == 'D')
	{
		mlx_destroy_window(p->mlx, p->window.ptr);
		exit(0);
	}
	if (p->map_p.c == 0)
	{
		p->success.sprite = ft_new_sprite(p->mlx, 'S');
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->success.sprite.ptr, \
			p->exit.pos.x, p->exit.pos.y);
	}
}

void	ft_go_up(t_p *p, int x, int y)
{
	p->map_p.map[y][x] = '0';
	if (p->map_p.map[y - 1][x] == '0')
	{
		ft_simple_movement(p, 'U', -128);
	}
	else if (p->map_p.map[y - 1][x] == 'E')
	{
		ft_handle_exit(p, 0);
	}
	else if (p->map_p.map[y - 1][x] == 'C')
	{
		ft_handle_coin(p, -128, 'U', -1);
	}
	else if (p->map_p.map[y - 1][x] == 'D')
	{
		mlx_destroy_window(p->mlx, p->window.ptr);
		exit(0);
	}
	if (p->map_p.c == 0)
	{
		p->success.sprite = ft_new_sprite(p->mlx, 'S');
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->success.sprite.ptr, \
			p->exit.pos.x, p->exit.pos.y);
	}
}

void	ft_go_down(t_p *p, int x, int y)
{
	p->map_p.map[y][x] = '0';
	if (p->map_p.map[y + 1][x] == '0')
	{
		ft_simple_movement(p, 'D', 128);
	}
	else if (p->map_p.map[y + 1][x] == 'E')
	{
		ft_handle_exit(p, 0);
	}
	else if (p->map_p.map[y + 1][x] == 'C')
	{
		ft_handle_coin(p, 128, 'D', 1);
	}
	else if (p->map_p.map[y + 1][x] == 'D')
	{
		mlx_destroy_window(p->mlx, p->window.ptr);
		exit(0);
	}
	if (p->map_p.c == 0)
	{
		p->success.sprite = ft_new_sprite(p->mlx, 'S');
		mlx_put_image_to_window(p->mlx, p->window.ptr, p->success.sprite.ptr, \
			p->exit.pos.x, p->exit.pos.y);
	}
}

int	ft_input(int key, t_p *p)
{
	int	x;
	int	y;

	x = p->player.pos.x / 128;
	y = p->player.pos.y / 128;
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
