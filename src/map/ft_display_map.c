#include "so_long.h"

void	ft_display_map(t_tile *ll_map, t_window *sl)
{
	int		x;
	int		y;
	
	ft_open_images(sl);
	while (ll_map)
	{
		x = ll_map->x * sl->pix_tile;
		y = ll_map->y * sl->pix_tile;
		if (ll_map->c == '0')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[0], x, y);
		else if (ll_map->c == '1')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[1], x, y);
		else if (ll_map->c == 'C')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[2], x, y);
		else if (ll_map->c == 'E')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[3], x, y);
		else if (ll_map->c == 'P')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imgs[4], x, y);
		ll_map = ll_map->next;
	}
}
