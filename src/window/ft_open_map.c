/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:33:41 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:48:30 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_map(t_tile *ll_map)
{
	t_window	*so_long;

	so_long = ft_open_window(ll_map);
	if (so_long == NULL)
	{
		free (ll_map);
		ft_exit_error_message("Open window issue");
	}
	ft_display_map(ll_map, so_long);
	ft_save_init_pos(so_long);
	mlx_key_hook(so_long->win_ptr, ft_key_hook, so_long);
	mlx_hook(so_long->win_ptr, 17, 0, ft_exit_success, so_long);
	mlx_loop(so_long->mlx_ptr);
}
