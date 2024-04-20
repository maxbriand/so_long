#include "so_long.h"

void ft_invalid_map_exit(int fd, char *buffer, char *full_text, int code)
{
	if (buffer == NULL)
		free(buffer);
	free(full_text);
	close(fd);
	if (code == 1)
		ft_exit_error_message("Map contains invalid character");
	if (code == 2)
		ft_exit_error_message("Map doesn't contain all characters");
	if (code == 3)
	{
		free(buffer);
		ft_exit_error_message("Map contain two E or P");	
	}
}
