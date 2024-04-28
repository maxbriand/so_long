/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_queue_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:34:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 18:15:01 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Add an element in the queue
t_queue	*ft_create_queue(t_tile *tile)
{
	t_queue	*pt_new_elem;

	pt_new_elem = malloc(sizeof(t_queue));
	if (pt_new_elem == 0)
		return (NULL);
	pt_new_elem->next = NULL;
	pt_new_elem->tile = tile;
	return (pt_new_elem);
}

void	ft_push_back_queue(t_queue **begin_list, void *data)
{
	t_queue	*node4;
	t_queue	*deref_begin_list;

	deref_begin_list = *begin_list;
	node4 = ft_create_queue(data);
	while (deref_begin_list->next != NULL)
		deref_begin_list = deref_begin_list->next;
	deref_begin_list->next = node4;
}
