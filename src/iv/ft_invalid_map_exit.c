/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_map_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:02:45 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/23 23:16:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_invalid_map_exit(char *components, char *full_text, int code)
{
	free(full_text);
	if (code == 1)
		ft_exit_error_message("Map contains invalid character");
	if (code == 2)
		ft_exit_error_message("Map doesn't contain all characters");
	if (code == 3)
	{
		free(components);
		ft_exit_error_message("Map contain two E or P");
	}
}
