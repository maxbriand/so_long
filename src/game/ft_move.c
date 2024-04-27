/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:26:55 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:27:34 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update_new_tile(t_window *sl, char c)
{
	t_tile	*current;

	current = ft_find_tile(sl->ll_map, sl->x_pcoor, sl->y_pcoor);
	if (c == MAP_EXIT)
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[5], \
			sl->x_pcoor * 50, sl->y_pcoor * 50);
	else
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[4], \
			sl->x_pcoor * 50, sl->y_pcoor * 50);
	if (c == COLLECTIBLE)
		current->c = EMPTY_SPACE;
}

static void	ft_update_old_tile(t_window *sl)
{
	if (sl->x_pcoor == sl->x_ecoor && sl->y_pcoor == sl->y_ecoor)
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[3], \
			sl->x_pcoor * 50, sl->y_pcoor * 50);
	else
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[0], \
			sl->x_pcoor * 50, sl->y_pcoor * 50);
}

void	ft_move(t_window *sl, int x_move, int y_move)
{
	char	c;

	c = ft_get_next_c(sl, x_move, y_move);
	if (c == WALL || sl->end == 1)
		return ;
	ft_update_old_tile(sl);
	sl->x_pcoor = sl->x_pcoor + x_move;
	sl->y_pcoor = sl->y_pcoor + y_move;
	ft_update_new_tile(sl, c);
	sl->counter += 1;
	ft_printf("Move: %d\n", sl->counter);
	if (c == MAP_EXIT)
		ft_game_end(sl);
}
