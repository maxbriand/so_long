#include "so_long.h"

void ft_invalid_map_exit(int fd, char *buffer)
{
	free(buffer);
	close(fd);
	ft_exit_error_message("Map contains invalid character");
}
