#include "so_long.h"

void	save_init_pos(t_window *so_long)
{
	t_tile	*ll_map;

	ll_map = so_long->ll_map;
	while (ll_map)
	{
		if (ll_map->c == 'E')
		{
			so_long->x_ecoor = (ll_map->x) * 50;
			so_long->y_ecoor = (ll_map->y) * 50;
		}	
		else if (ll_map->c == 'P')	
		{
			so_long->x_pcoor = (ll_map->x) * 50;
			so_long->y_pcoor = (ll_map->y) * 50;
		}	
		ll_map = ll_map->next;
	}
}