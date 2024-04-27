/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_init_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:37:36 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:37:57 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	save_init_pos(t_window *so_long)
{
	t_tile	*ll_map;

	ll_map = so_long->ll_map;
	while (ll_map)
	{
		if (ll_map->c == 'E')
		{
			so_long->x_ecoor = (ll_map->x);
			so_long->y_ecoor = (ll_map->y);
		}
		else if (ll_map->c == 'P')
		{
			so_long->x_pcoor = (ll_map->x);
			so_long->y_pcoor = (ll_map->y);
		}
		ll_map = ll_map->next;
	}
}
