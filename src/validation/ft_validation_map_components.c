#include "so_long.h"

void	ft_validation_map_components(char *map)
{
	int 	fd;
	char	*buffer;

	fd = open (map, O_RDONLY);
	if (fd == -1)
		perror("Error\n");
	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		free(buffer);
	}
	close(fd);
}
