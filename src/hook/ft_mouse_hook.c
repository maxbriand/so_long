#include "so_long.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	ft_printf("%d and %d and %d", x, y, button);
	return (0);
}
