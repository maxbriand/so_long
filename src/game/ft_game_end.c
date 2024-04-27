#include "so_long.h"

static t_tile	*ft_collectible_search(t_tile *ll_map)
{
	while (ll_map)
	{
		if (ll_map->c == COLLECTIBLE)
			break ;
		ll_map = ll_map->next;
	}
	return (ll_map);
}

void 	ft_game_end(t_window *sl)
{
	if (ft_collectible_search(sl->ll_map) != NULL)
		return ;
	sl->end = 1;
	ft_printf("You win!\n");
}
