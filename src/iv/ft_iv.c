/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:02:13 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/23 23:42:19 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		perror("Error\n");
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
			tile = ft_create_tile(x, y, c);
		else
			ft_tile_push_back(&tile, x, y, c);
		x++;
		full_text++;
	}
	return (tile);
}

// if I nead to get the map outside of this function, add a t_tile
// as parameter
void	ft_iv(char *map)
{
	char	*full_text;
	t_tile	*ll_map;

	ft_iv_map_extension(map);
	full_text = ft_get_full_text(map);
	ft_iv_map_components(full_text);
	ft_iv_map_rectangular(full_text);
	ft_iv_map_closed(full_text);
	ll_map = ft_convert_str_to_ll(full_text);
	free(full_text);
	ft_iv_map_path(ll_map);
}
// TO CLEAN THE LL	
	// t_tile	*save_tile;
	// while (ll_map)
	// {
	// 	save_tile = ll_map;
	// 	ll_map = ll_map->next;
	// 	free(save_tile);
	// }
// I have to free the linked list now
