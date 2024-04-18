#include "mlx.h"
#include <unistd.h>
#include "libft.h"

typedef struct 	s_params
{
	void 		*mlx_ptr;
	void 		*win_ptr;
}				t_params;

// int mouse_hook(int button, int x, int y, void *params)
// {
// 	ft_printf("%d", button);
// }

int	key_hook_white(int key, void *params)
{
	int color = 0xFFFFFF;
	int width = 200;
	int height = 200;
	t_params *paramss = params;

	if (key == 'a')
	{
		while (width <= 400)
		{
			while(height <= 400)
			{
				mlx_string_put (paramss->mlx_ptr, paramss->win_ptr, width, height, color, "H");
				height += 20;
			}
			height = 200;
			width++;
		}
	}
	if (key == 'z')
	{
		while (width <= 400)
		{
			while(height <= 400)
			{
				mlx_string_put (paramss->mlx_ptr, paramss->win_ptr, width, height, 0xFF9900, "H");
				height += 20;
			}
			height = 200;
			width++;
		}
	}
	if (key == 'e')
		mlx_clear_window(paramss->mlx_ptr, paramss->win_ptr);
	if (key == 'r')
		mlx_destroy_window(paramss->mlx_ptr, paramss->win_ptr);
	return (0);
}

int	expose_hook(void *params)
{
	int color = 0xA64D79;
	int width = 200;
	int height = 200;
	t_params *paramss = params;

	while (width <= 400)
	{
		while(height <= 400)
		{
			mlx_string_put (paramss->mlx_ptr, paramss->win_ptr, width, height, color, "H");
			height += 20;
		}
		height = 200;
		width++;
	}
	return (0);
}

int	main(void)
{
	t_params params;
	params.mlx_ptr = mlx_init();
	int color = 0xFF0000;
	int width = 200;
	int height = 200;

	params.win_ptr = mlx_new_window(params.mlx_ptr, 1000, 1000, "Hello blue");
	while (width <= 400)
	{
		while(height <= 400)
		{
			mlx_string_put (params.mlx_ptr, params.win_ptr, width, height, color, "H");
			height += 20;
		}
		height = 200;
		width++;
	}
	mlx_key_hook(params.win_ptr, key_hook_white, &params);	
	
	char *relativ_path = "./c_one.xmp";
	int		img_width;
	int		img_height;
	mlx_xpm_file_to_image(params.mlx_ptr, relativ_path, &img_width, &img_height);
	void *img_ptr;
	int ii_height = 100;
	int ii_width = 100;
	img_ptr = mlx_new_image (params.mlx_ptr, ii_width, ii_height);
	mlx_put_image_to_window (params.mlx_ptr, params.win_ptr, img_ptr, 600, 700);

	//mlx_expose_hook (params.win_ptr, expose_hook, &params);
	// mlx_mouse_hook (params.win_ptr, mouse_hook, params);
	int resss = mlx_loop(params.mlx_ptr);
	ft_printf("the result of mlx loop is %d", resss);
	return (0);
}