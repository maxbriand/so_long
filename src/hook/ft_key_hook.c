#include "so_long.h"

int	key_hook(int keycode, void *so_long)
{
	// esc
	if (keycode == 65307)
		ft_exit_success(so_long);
	// up
	// if (keycode == 122)
	// 	ft_move_up(so_long);
	// down
	//if (keycode == 115)
	// right
	//if (keycode == 100)
	// left
	//if (keycode == 113)
	return (0);
}
