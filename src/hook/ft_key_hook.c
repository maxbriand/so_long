#include "so_long.h"

int	key_hook(int keycode, void *so_long)
{
	// esc
	if (keycode == 65307)
	{
		ft_close_window(so_long);
		exit(EXIT_SUCCESS);
	}
	// up
	//if (keycode == 122)
	// down
	//if (keycode == 115)
	// right
	//if (keycode == 100)
	// left
	//if (keycode == 113)
	return (0);
}
