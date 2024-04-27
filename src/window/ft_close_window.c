/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:29:10 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:29:39 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_images(t_window *so_long)
{
	int	**imgs;
	int	i;

	i = 0;
	imgs = so_long->imgs;
	if (imgs != NULL)
	{
		while (imgs[i])
		{
			mlx_destroy_image(so_long->mlx_ptr, imgs[i]);
			i++;
		}
	}
	free(so_long->imgs);
}

void	ft_close_window(t_window *so_long)
{
	if (so_long->imgs != NULL)
		ft_close_images(so_long);
	if (so_long->win_ptr != NULL)
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	if (so_long->mlx_ptr != NULL)
		mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	free(so_long);
}
