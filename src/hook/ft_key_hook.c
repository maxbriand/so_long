/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:33:59 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:34:00 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *so_long)
{
	if (keycode == 65307)
		ft_exit_success(so_long);
	if (keycode == 122)
		ft_move(so_long, 0, -1);
	if (keycode == 115)
		ft_move(so_long, 0, 1);
	if (keycode == 100)
		ft_move(so_long, 1, 0);
	if (keycode == 113)
		ft_move(so_long, -1, 0);
	return (0);
}
