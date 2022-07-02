/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:22:22 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 20:47:00 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp_l;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp_l = ft_lstlast(*lst);
		tmp_l->next = new;
	}
}
