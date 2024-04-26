#include "so_long.h"


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
