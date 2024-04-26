#include "so_long.h"

int	**ft_open_images(t_window *sl)
{
	int	**imgs;

	imgs = malloc(sizeof(int *) * 7);
	if	(imgs == NULL)
		return (NULL);
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
	return (imgs);
}

