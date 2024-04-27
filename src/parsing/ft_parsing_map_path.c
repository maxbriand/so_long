/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:34:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:34:49 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_c_number(t_tile *tile)
{
	int	c_number;

	c_number = 0;
	while (tile)
	{
		if (tile->c == COLLECTIBLE)
			c_number++;
		tile = tile->next;
	}
	return (c_number);
}

static void	ft_invalid_map(t_tile *map)
{
	ft_free_map_tile(map);
	ft_exit_error_message("The path is invalid");
}

static void	ft_handle_tile(t_tile *around_tile, t_queue *queue)
{
	if (around_tile->visited == 0 && around_tile->c != WALL)
	{
		around_tile->visited = 1;
		ft_push_back_queue(&queue, around_tile);
	}
}

void	ft_around_tile_checker(t_queue *queue, t_tile *tile)
{
	int		x;
	int		y;
	t_tile	*around_tile;

	x = queue->tile->x;
	y = queue->tile->y;
	around_tile = ft_find_tile(tile, x, y - 1);
	ft_handle_tile(around_tile, queue);
	around_tile = ft_find_tile(tile, x, y + 1);
	ft_handle_tile(around_tile, queue);
	around_tile = ft_find_tile(tile, x - 1, y);
	ft_handle_tile(around_tile, queue);
	around_tile = ft_find_tile(tile, x + 1, y);
	ft_handle_tile(around_tile, queue);
}

// Breadth-First Search algorith (BFS)
void	ft_parsing_map_path(t_tile *ll_map)
{
	t_tile	*starting_p;
	t_queue	*queue;
	t_queue	*save_queue;
	int		c_number;
	int		counter;

	starting_p = ft_find_starting_p(ll_map);
	starting_p->visited = 1;
	c_number = ft_c_number(ll_map);
	counter = 0;
	queue = ft_create_queue(starting_p);
	while (queue)
	{
		if (queue->tile->c == COLLECTIBLE || queue->tile->c == MAP_EXIT)
			counter++;
		ft_around_tile_checker(queue, ll_map);
		save_queue = queue;
		queue = queue->next;
		free(save_queue);
	}
	if (counter != (c_number + 1))
		ft_invalid_map(ll_map);
}
