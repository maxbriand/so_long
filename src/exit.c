/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:26:11 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/28 16:23:46 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_tile(t_tile *map)
{
	t_tile	*save_tile;

	while (map)
	{
		save_tile = map;
		map = map->next;
		free(save_tile);
	}
}

void	ft_exit_error_message(char *message)
{
	write(2, "Error\n", 6);
	while (*message)
	{
		write(2, &(*message), 1);
		message++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_exit_failure(char *message, t_window *so_long)
{
	if (so_long != NULL)
	{
		if (so_long->ll_map != NULL)
			ft_free_map_tile(so_long->ll_map);
		ft_close_window(so_long);
	}
	ft_exit_error_message(message);
}

int	ft_exit_success(t_window *so_long)
{
	ft_free_map_tile(so_long->ll_map);
	ft_close_window(so_long);
	exit(EXIT_SUCCESS);
	return (0);
}
