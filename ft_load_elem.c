/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:12 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/24 17:38:13 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_wall(t_p *p)
{
	p->e[5].sprite.ptr = p->sprite.ptr;
}

void	ft_load_exit(t_p *p, int i, int j)
{
	p->e[3].pos.x = j * 128;
	p->e[3].pos.y = i * 128;
	p->e[3].sprite.ptr = p->sprite.ptr;
}

void	ft_load_coin(t_p *p)
{
	p->e[4].sprite.ptr = p->sprite.ptr;
}

void	ft_load_floor(t_p *p)
{
	p->e[1].sprite.ptr = p->sprite.ptr;
}

void	ft_load_player(t_p *p, int i, int j)
{
	p->e[0].pos.x = j * 128;
	p->e[0].pos.y = i * 128;
	p->e[0].sprite.ptr = p->sprite.ptr;
}
