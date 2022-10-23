/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:42:36 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/23 22:42:55 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
