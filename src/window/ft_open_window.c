#include "so_long.h"

static int	ft_coor_max(t_tile *ll_map, int x_or_y)
{
	int coor_max;

	coor_max = 0;
	while (x_or_y == 0 && ll_map->next->y == 0)
	{
		coor_max++;
		ll_map = ll_map->next;
	}
	while ((x_or_y == 1 && ll_map->next))
	{
		coor_max = ll_map->y;
		ll_map = ll_map->next;
	}
	coor_max++;
	return (coor_max);
}

t_window	*ft_open_window(t_tile *ll_map)
{
	t_window	*so_long;

	so_long = malloc(sizeof(t_window));
	if (so_long == NULL)
		return (NULL);
	so_long->pix_tile = 50;
	so_long->imgs = NULL;
	so_long->ll_map = ll_map;
	so_long->size_x = ft_coor_max(ll_map, 0) * 50;
	so_long->size_y = ft_coor_max(ll_map, 1) * 50;
	so_long->mlx_ptr = mlx_init();
	if (so_long->mlx_ptr == NULL)
	{
		free(so_long);
		return (NULL);
	}
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->size_x, \
	so_long->size_y, "so_long");
	if (so_long->win_ptr == NULL)
	{
		free(so_long);
		return (NULL);
	}
	return (so_long);
}