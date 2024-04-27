/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:34:42 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/27 17:34:43 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_map_extension(char *map)
{
	int		len_name;
	char	*extension;

	len_name = ft_strlen(map);
	extension = map + len_name - 4;
	if (ft_strcmp(extension, ".ber") != 0)
		ft_exit_error_message("Not a .ber map");
}
