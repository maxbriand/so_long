#include "so_long.h"

int	ft_close_window(t_window *so_long)
{
	ft_printf("%d\n", so_long->size_x);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	free(so_long);
	exit(EXIT_SUCCESS);
	return(0);
}
