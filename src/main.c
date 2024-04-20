#include "so_long.h"

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
	char	*map;
	
	ac -= 1;
	av = av + 1;
	if (ac <= 0)
		ft_exit_error_message("Too few arguments");
	if (ac > 1)
		ft_exit_error_message("Too many arguments");
	map = *av;
	ft_validation(map);
	return (0);
}
