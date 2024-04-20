#include "mlx.h"
#include <unistd.h>
#include "libft.h"
#include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct 	s_params
{
	void 		*mlx_ptr;
	void 		*win_ptr;
	int			*x;
	int			*y;
}				t_params;

int	key_hook_white(int key, void *params)
{
	int color = 0xFFFFFF;
	int width = 0;
	int height = 0;
	t_params *paramss = params;

	char 	*relativ_path = "./textures/death_0.xpm";
	int		img_width;
	int		img_height;
	void 	*img_ptr;
	img_ptr = mlx_xpm_file_to_image(paramss->mlx_ptr, relativ_path, &img_width, &img_height);

	char 	*relativ_path_walk = "./textures/walk_3.xpm";
	// int		img_width;
	// int		img_height;
	void 	*img_ptr_two;
	img_ptr_two = mlx_xpm_file_to_image(paramss->mlx_ptr, relativ_path_walk, &img_width, &img_height);

	if (key == 'n')
	{
		while (width <= 1000)
		{
			while(height <= 1000)
			{
				mlx_pixel_put (paramss->mlx_ptr, paramss->win_ptr, width, height, color);
				height += 1;
			}
			height = 0;
			width++;
		}
	}
	if (key == 'b')
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
	if (key == 'y')
		mlx_clear_window(paramss->mlx_ptr, paramss->win_ptr);
	// if (key == 'r')
	// 	mlx_destroy_window(paramss->mlx_ptr, paramss->win_ptr);
	if (key == 'a' && img_ptr != NULL)
	{
		int test = mlx_put_image_to_window (paramss->mlx_ptr, paramss->win_ptr, img_ptr, 0, 0);
		ft_printf("%d", test);
	}
	// up
	if (key == 'z' && img_ptr != NULL)
	{
		*(paramss->y) -= 100;
		int test2 = mlx_put_image_to_window (paramss->mlx_ptr, paramss->win_ptr, img_ptr, *(paramss->x), *(paramss->y));
		ft_printf("%d", test2);	
	}
	// left
	if (key == 'q' && img_ptr_two)
	{
		*(paramss->x) -= 100;
		mlx_put_image_to_window (paramss->mlx_ptr, paramss->win_ptr, img_ptr_two, *(paramss->x), *(paramss->y));
	}
	// right
	if (key == 'd' && img_ptr)
	{
		*(paramss->x) += 100;		
		mlx_put_image_to_window (paramss->mlx_ptr, paramss->win_ptr, img_ptr, *(paramss->x), *(paramss->y));
	}
	// low
	if (key == 's' && img_ptr)
	{
		*(paramss->y) += 100;		
		mlx_put_image_to_window (paramss->mlx_ptr, paramss->win_ptr, img_ptr, *(paramss->x), *(paramss->y));
	}
	// ft_printf("%c", key);
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

/*int	main(void)
{
	t_params params;
	params.mlx_ptr = mlx_init();
	// int color = 0xFF0000;
	// int width = 200;
	// int height = 200;
	int x = 400;
	int y = 400;
	params.x = &x;
	params.y = &y;

	params.win_ptr = mlx_new_window(params.mlx_ptr, 1000, 1000, "Hello blue");
	mlx_key_hook(params.win_ptr, key_hook_white, &params);		
	//mlx_expose_hook (params.win_ptr, expose_hook, &params);
	// mlx_mouse_hook (params.win_ptr, mouse_hook, params);
	int infit = mlx_loop(params.mlx_ptr);
	ft_printf("the result of mlx loop is %d", infit);
	return (0);
}*/

int	main(void)
{
	
	int fd;
	char *str;
	fd = open("textures/ok_medium_map.ber", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		printf("\n");
	}
	free(str);
	return (0);
}

