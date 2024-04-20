#include "so_long.h"

static char	*ft_get_full_text(char *map)
{
	int 	fd;
	char	*buffer;
	char	*full_text;
	char	*old_full_text;

	fd = open (map, O_RDONLY);
	if (fd == -1)
		perror("Error\n");
	full_text = NULL;
	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		if (full_text != NULL)
		{
			old_full_text = full_text;
			full_text = ft_strjoin(full_text, buffer);
			free(old_full_text);
		}
		else
			full_text = ft_strdup(buffer);
		free(buffer);
	}
	close(fd);
	return (full_text);
}

void	ft_validation(char *map)
{
	char	*full_text;
	
	ft_validation_map_extension(map);
	full_text = ft_get_full_text(map);
	ft_printf("%s", full_text);
	return;
	ft_validation_map_components(map);
	ft_validation_rectangular(full_text);
	free(full_text);
}
