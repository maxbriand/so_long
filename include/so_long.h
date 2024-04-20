#ifndef SO_LONG_H
	#define SO_LONG_H

#ifndef EMPTY_SPACE
	#define EMPTY_SPACE "0"
#endif

#ifndef WALL
	#define WALL "1"
#endif

#ifndef COLLECTIBLE
	#define COLLECTIBLE "C"
#endif

#ifndef MAP_EXIT
	#define MAP_EXIT "E"
#endif

#ifndef START_POSITION
	#define START_POSITION "P"
#endif

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_exit_error_message(char *message);

// map / input validation
void	ft_validation(char *map);
void	ft_validation_map_extension(char *map);
void	ft_validation_map_components(char *map);

#endif