#include "so_long.h"

void	ft_free_map_tile(t_tile *map)
{
	t_tile	*save_tile;

	while (map)
	{
		save_tile = map;
		map = map->next;
		free(save_tile);
	}
}

void	ft_exit_error_message(char *message)
{
	write(2, "Error\n", 6);
	while (*message)
	{
		write(2, &(*message), 1);
		message++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	char	*path;
//	char	**images;
	t_tile	*ll_map;

	ac -= 1;
	av = av + 1;
	if (ac <= 0)
		ft_exit_error_message("Too few arguments");
	if (ac > 1)
		ft_exit_error_message("Too many arguments");
	path = *av;
	ll_map = ft_parsing(path);
	ft_open_map(ll_map);
	return (0);
}
