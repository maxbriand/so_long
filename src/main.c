/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:25:38 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/28 15:58:33 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*path;
	t_tile	*ll_map;

	ac -= 1;
	av = av + 1;
	if (ac <= 0)
		ft_exit_error_message("Too few arguments");
	if (ac > 1)
		ft_exit_error_message("Too many arguments");
	path = *av;
	ll_map = ft_parsing(path);
	ft_open_map(ll_map);
	return (0);
}
