/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:37:19 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:37:20 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_error_img_ptr(int **imgs, t_window *sl)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (imgs[i] == NULL)
			ft_exit_failure("Open map issue", sl);
		i++;
	}
}

void	ft_open_images(t_window *sl)
{
	int	**imgs;

	imgs = malloc(sizeof(int *) * 7);
	if (imgs == NULL)
		ft_exit_failure("Open map issue", sl);
	imgs[0] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/0.xpm", \
	&(sl->pix_tile), &(sl->pix_tile));
	imgs[1] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/1.xpm", \
	&(sl->pix_tile), &(sl->pix_tile));
	imgs[2] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/C.xpm", \
	&(sl->pix_tile), &(sl->pix_tile));
	imgs[3] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/E.xpm", \
	&(sl->pix_tile), &(sl->pix_tile));
	imgs[4] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/P.xpm", \
	&(sl->pix_tile), &(sl->pix_tile));
	imgs[5] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/E2.xpm", \
	&(sl->pix_tile), &(sl->pix_tile));
	imgs[6] = NULL;
	ft_check_error_img_ptr(imgs, sl);
	sl->imgs = imgs;
}
