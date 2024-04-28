/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_lenght.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:10:31 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/28 16:24:21 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_lenght(char *full_text)
{
	int	i;

	i = 0;
	while (full_text[i])
	{
		if (full_text[i] == '\n')
			break ;
		i++;
	}
	if (i > 100)
		ft_invalid_map_exit(NULL, full_text, 4);
}
