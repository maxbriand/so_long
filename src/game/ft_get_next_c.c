#include "so_long.h"

char	ft_get_next_c(t_window *sl, int	x_move, int y_move)
{
	t_tile	*tile;

	tile = ft_find_tile(sl->ll_map, sl->x_pcoor + x_move / 1, \
		sl->y_pcoor + y_move / 1);
	return (tile->c);
}
