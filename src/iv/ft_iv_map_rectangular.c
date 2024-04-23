/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iv_map_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:03:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/23 23:15:16 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_exit_iv_rectangular(char *full_text)
{
	free(full_text);
	ft_exit_error_message("Map is not rectangular");
}

static int	ft_len_ref(char *full_text)
{
	int	ref;

	ref = 0;
	while (*full_text && *full_text != '\n')
	{
		ref++;
		full_text++;
	}
	return (ref);
}

void	ft_iv_map_rectangular(char *full_text)
{
	int		ref;
	int		candidate;
	char	*save_full_text;

	ref = ft_len_ref(full_text);
	candidate = 0;
	save_full_text = full_text;
	while (*full_text)
	{
		if (*full_text == '\n')
		{
			if (candidate != ref)
				ft_exit_iv_rectangular(save_full_text);
			candidate = 0;
			full_text++;
		}
		candidate++;
		full_text++;
	}
	if (candidate != ref)
		ft_exit_iv_rectangular(save_full_text);
}
