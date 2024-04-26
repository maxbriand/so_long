#include "so_long.h"

void	ft_parsing_map_extension(char *map)
{
	int		len_name;
	char	*extension;

	len_name = ft_strlen(map);
	extension = map + len_name - 4;
	if (ft_strcmp(extension, ".ber") != 0)
		ft_exit_error_message("Not a .ber map");
}
