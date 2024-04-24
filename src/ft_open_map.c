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

void	ft_put_map_elements(t_tile *ll_map, void *mlx_ptr, void *win_ptr)
{
	int		width;
	int		height;
	int		x;
	int		y;
	void	*img_ptr;
	
	width = 50;
	height = 50;
	while (ll_map)
	{
		x = (ll_map->x) * 50;
		y = (ll_map->y) * 50;
		if (ll_map->c == EMPTY_SPACE || ll_map->c == 'C' || ll_map->c == 'P' \
			|| ll_map->c == 'E')
		{
			img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/02.xpm", &width, &height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
		}
		if (ll_map->c == WALL)
		{
			img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/1.xpm", &width, &height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
		}
		if (ll_map->c == 'C')
		{
			img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/C.xpm", &width, &height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
		}
		ll_map = ll_map->next;
	}
}

t_window	*ft_open_window(t_tile *ll_map)
{
	t_window	*so_long;
	void		*mlx_ptr;
	void		*win_ptr;
	int			size_x;
	int			size_y;

	so_long = malloc(sizeof(t_window));
	if (so_long == NULL)
		return (NULL);
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

int	ft_close_window(t_window *so_long)
{
	ft_printf("%d\n", so_long->size_x);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	free(so_long);
	exit(EXIT_SUCCESS);
	return(0);
}

int	key_hook(int keycode, void *so_long)
{
	// esc
	if (keycode == 65307)
		ft_close_window(so_long);
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

int	mouse_hook(int button, int x, int y, void *param)
{
	ft_printf("%d and %d and %d", x, y, button);
	return (0);
}

void ft_open_images()
{
	void *img_ptr

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "filename", width, height);
}

void	ft_open_map(t_tile *ll_map)
{
	t_window	*so_long;

	so_long = ft_open_window(ll_map);
	if (so_long == NULL)
		ft_exit_error_message("Open window issue");
	//ft_open_images();
	mlx_key_hook(so_long->win_ptr, key_hook, so_long);
	mlx_mouse_hook(so_long->win_ptr, mouse_hook, so_long);
	mlx_hook(so_long->win_ptr, 17, 0, ft_close_window, so_long);
	mlx_loop(so_long->mlx_ptr);	
	// handle win_ptr fail?
	// ft_put_map_elements(ll_map, mlx_ptr, win_ptr);
	// ft_close_window(); // free so_long window structure + destroy properly
}