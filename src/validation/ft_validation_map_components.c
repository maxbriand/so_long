#include "so_long.h"

static void	ft_invalid_character(int fd, char *buffer, char *full_text)
{
	char *save_buffer;

	save_buffer = buffer;	
	while (*buffer && *buffer != '\n')
	{
		if (*(buffer) != EMPTY_SPACE && *(buffer) != WALL \
		&& *(buffer) != COLLECTIBLE && *(buffer) != MAP_EXIT \
		&& *(buffer) != START_POS)
			ft_invalid_map_exit(fd, save_buffer, full_text, 1);
		buffer++;
	}
}	

void	ft_all_components_check(int fd, char *full_text)
{
	char 	*components;
	char	*save_components;

	components = ft_strdup("01CEP");
	save_components = components;
	while (*components)
	{
		if (ft_strrchr(full_text, *components) == NULL)
		{
			free(save_components);
			ft_invalid_map_exit(fd, NULL, full_text, 2);
		}
		components++;
	}
	free(save_components);
}

void	ft_redundant_character(int fd, char *full_text)
{
	int		counter;
	int		i;
	char	*components;
	char	*save_components;

	i = 0;
	counter = 0;
	components = ft_strdup("PE");
	save_components = components;
	while (*components)
	{
		if (full_text[i] == *components)
			counter++;
		if (counter > 1)
			ft_invalid_map_exit(fd, save_components, full_text, 3);
		i++;
		if (!full_text[i])
		{
			components++;
			counter = 0;
			i = 0;
		}
	}
	free (save_components);
}

char	*ft_validation_map_components(char *map)
{
	int 	fd;
	char	*buffer;
	char	*full_text;

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
		if (full_text == NULL)
			full_text = ft_strdup(buffer);
		else
		{
			
			full_text = ft_strjoin(full_text, buffer);
		}
		ft_invalid_character(fd, buffer, full_text);
		free(buffer);
	}
	ft_all_components_check(fd, full_text);
	ft_redundant_character(fd, full_text);
	close(fd);
	return(full_text);
}
