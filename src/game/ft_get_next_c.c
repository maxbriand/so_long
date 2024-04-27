/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:28:24 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:28:53 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_get_next_c(t_window *sl, int x_move, int y_move)
{
	t_tile	*tile;

	tile = ft_find_tile(sl->ll_map, sl->x_pcoor + x_move / 1, \
		sl->y_pcoor + y_move / 1);
	return (tile->c);
}
