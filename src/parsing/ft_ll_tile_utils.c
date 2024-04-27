/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_tile_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:34:22 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:34:23 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Create an element of the list
t_tile	*ft_create_tile(int x, int y, char c)
{
	t_tile	*pt_new_elem;

	pt_new_elem = malloc(sizeof(t_tile));
	if (pt_new_elem == 0)
		return (NULL);
	pt_new_elem->next = NULL;
	pt_new_elem->x = x;
	pt_new_elem->y = y;
	pt_new_elem->c = c;
	pt_new_elem->visited = 0;
	return (pt_new_elem);
}

// Add a node at the end of the linked list
void	ft_tile_push_back(t_tile **begin_list, int x, int y, char c)
{
	t_tile	*new_node;
	t_tile	*deref_begin_list;

	deref_begin_list = *begin_list;
	new_node = ft_create_tile(x, y, c);
	while (deref_begin_list->next != NULL)
		deref_begin_list = deref_begin_list->next;
	deref_begin_list->next = new_node;
}

t_tile	*ft_find_tile(t_tile *tile, int x, int y)
{
	while (tile)
	{
		if (tile->x == x && tile->y == y)
			break ;
		tile = tile->next;
	}
	return (tile);
}

// don't forget to free the queue
t_tile	*ft_find_starting_p(t_tile *tile)
{
	while (tile)
	{
		if (tile->c == START_POS)
			break ;
		tile = tile->next;
	}
	return (tile);
}
