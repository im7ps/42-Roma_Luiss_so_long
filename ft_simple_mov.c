/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_mov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:54:29 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/23 22:54:52 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_simple_movement(t_p *p, char dir, int d_value)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr, \
		p->e[1].sprite.ptr, p->e[0].pos.x, p->e[0].pos.y);
	if (dir == 'L' || dir == 'R')
	{
		p->e[0].pos.x += d_value;
	}
	else if (dir == 'U' || dir == 'D')
	{
		p->e[0].pos.y += d_value;
	}
	mlx_put_image_to_window(p->mlx, p->window.ptr, \
		p->e[0].sprite.ptr, p->e[0].pos.x, p->e[0].pos.y);
	ft_update_score(p);
}

void	ft_vertical_mov(t_p *p, int d_value, int s_value)
{
	int	x;
	int	y;

	x = p->e[0].pos.x / 128;
	y = p->e[0].pos.y / 128;
	p->map_p.map[y + d_value][x] = '0';
	p->e[0].pos.y += s_value;
}

void	ft_horizontal_mov(t_p *p, int d_value, int s_value)
{
	int	x;
	int	y;

	x = p->e[0].pos.x / 128;
	y = p->e[0].pos.y / 128;
	p->map_p.map[y][x + d_value] = '0';
	p->e[0].pos.x += s_value;
}
