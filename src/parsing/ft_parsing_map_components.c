#include "so_long.h"

static void	ft_redundant_character(char *full_text)
{
	int		counter;
	int		i;
	char	*components;
	char	*save_components;

	i = 0;
	counter = 0;
	components = ft_strdup("EP");
	save_components = components;
	while (*components)
	{
		if (full_text[i] == *components)
			counter++;
		if (counter > 1)
			ft_invalid_map_exit(save_components, full_text, 3);
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

static void	ft_all_components_check(char *full_text)
{
	char	*components;
	char	*save_components;

	components = ft_strdup("01CEP");
	save_components = components;
	while (*components)
	{
		if (ft_strrchr(full_text, *components) == NULL)
			ft_invalid_map_exit(save_components, full_text, 2);
		components++;
	}
	free(save_components);
}

static void	ft_invalid_character(char *full_text)
{
	char	*save_full_text;

	save_full_text = full_text;
	while (*full_text)
	{
		if (*(full_text) != EMPTY_SPACE && *(full_text) != WALL \
		&& *(full_text) != COLLECTIBLE && *(full_text) != MAP_EXIT \
		&& *(full_text) != START_POS && *(full_text) != '\n')
			ft_invalid_map_exit(NULL, save_full_text, 1);
		full_text++;
	}
}

void	ft_parsing_map_components(char *full_text)
{
	ft_invalid_character(full_text);
	ft_all_components_check(full_text);
	ft_redundant_character(full_text);
	return ;
}
