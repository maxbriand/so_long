#include "so_long.h"

static void	ft_invalid_map(char *full_text, int code)
{
	free(full_text);
	if (code == 1)
		ft_exit_error_message("The top wall is not closed");
	if (code == 2)
		ft_exit_error_message("The down wall is not closed");
	if (code == 3)
		ft_exit_error_message("A side wall is not closed");
}

static void	ft_parsing_map_closed_side(char *full_text)
{
	int	i;

	i = 0;
	while (full_text[i])
	{
		if (full_text[i] == '\n')
		{
			if (full_text[i - 1] != WALL || full_text[i + 1] != WALL)
				ft_invalid_map(full_text, 3);
		}
		i++;
	}
}

static void	ft_parsing_map_closed_down(char *full_text)
{
	char	*save_full_text;
	int		number_new_line;
	int		counter_new_line;

	save_full_text = full_text;
	number_new_line = ft_count_char(full_text, '\n');
	counter_new_line = 0;
	while (*full_text && counter_new_line < number_new_line)
	{
		if (*full_text == '\n')
			counter_new_line++;
		full_text++;
	}
	while (*full_text)
	{
		if (*full_text != WALL)
			ft_invalid_map(save_full_text, 2);
		full_text++;
	}
}

static void	ft_parsing_map_closed_up(char *full_text)
{
	char	*save_full_text;

	save_full_text = full_text;
	while (*full_text && *full_text != '\n')
	{
		if (*full_text != '1')
			ft_invalid_map(save_full_text, 1);
		full_text++;
	}
}

void	ft_parsing_map_closed(char *full_text)
{
	ft_parsing_map_closed_up(full_text);
	ft_parsing_map_closed_down(full_text);
	ft_parsing_map_closed_side(full_text);
}
