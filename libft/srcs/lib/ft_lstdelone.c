/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:30:22 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:08 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = lst;
	if (lst != NULL)
	{
		lst = tmp->next;
		del(tmp->content);
		free(tmp);
	}
}
