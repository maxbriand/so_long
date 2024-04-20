#include "so_long.h"

static void	ft_invalid_character(int fd, char *buffer)
{
	char *save_buffer;

	save_buffer = buffer;	
	while (*buffer && *buffer != '\n')
	{
		if (*(buffer) != EMPTY_SPACE && *(buffer) != WALL \
		&& *(buffer) != COLLECTIBLE && *(buffer) != MAP_EXIT \
		&& *(buffer) != START_POS)
			ft_invalid_map_exit(fd, save_buffer);
		buffer++;
	}
}	

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
		ft_invalid_character(fd, buffer);
		free(buffer);
	}
	close(fd);
}
