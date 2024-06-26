/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:34:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/28 16:23:17 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_open_error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

static char	*ft_new_full_text(char *full_text, char *buffer)
{
	char	*old_full_text;

	old_full_text = full_text;
	full_text = ft_strjoin(full_text, buffer);
	free(old_full_text);
	return (full_text);
}

static char	*ft_get_full_text(char *map)
{
	int		fd;
	char	*buffer;
	char	*full_text;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_open_error();
	full_text = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (full_text != NULL)
			full_text = ft_new_full_text(full_text, buffer);
		else
			full_text = ft_strdup(buffer);
		free(buffer);
	}
	close(fd);
	return (full_text);
}

t_tile	*ft_convert_str_to_ll(char *full_text)
{
	t_tile	*tile;
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (*full_text)
	{
		if (*full_text == '\n')
		{
			x = 0;
			y++;
			full_text++;
		}
		c = *full_text;
		if (x == 0 && y == 0)
			tile = ft_create_tile(x, y, c, full_text);
		else
			ft_tile_push_back(&tile, x, y, c);
		x++;
		full_text++;
	}
	return (tile);
}

t_tile	*ft_parsing(char *path)
{
	char	*full_text;
	t_tile	*ll_map;

	ft_parsing_map_extension(path);
	full_text = ft_get_full_text(path);
	ft_parsing_lenght(full_text);
	ft_parsing_map_components(full_text);
	ft_parsing_map_rectangular(full_text);
	ft_parsing_map_closed(full_text);
	ll_map = ft_convert_str_to_ll(full_text);
	free(full_text);
	ft_parsing_map_path(ll_map);
	return (ll_map);
}
