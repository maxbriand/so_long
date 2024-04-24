#ifndef SO_LONG_H
	#define SO_LONG_H

#ifndef EMPTY_SPACE
	#define EMPTY_SPACE '0'
#endif

#ifndef WALL
	#define WALL '1'
#endif

#ifndef COLLECTIBLE
	#define COLLECTIBLE 'C'
#endif

#ifndef MAP_EXIT
	#define MAP_EXIT 'E'
#endif

#ifndef START_POS
	#define START_POS 'P'
#endif

typedef	struct	s_tile
{
	int 			x;
	int 			y;
	char			c;
	int				visited;
	struct s_tile	*next;
} t_tile;

typedef struct	s_queue
{
	struct s_tile	*tile;
	struct s_queue	*next;
} t_queue;

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
} t_window;

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_exit_error_message(char *message);
void	ft_free_map_tile(t_tile *map);

// input validation - map
t_tile	*ft_iv(char *path);
void	ft_iv_map_extension(char *map);
void	ft_iv_map_components(char *full_text);
void	ft_iv_map_rectangular(char *full_text);
void	ft_iv_map_closed(char *full_text);
void	ft_iv_map_path(t_tile *ll_map);
void 	ft_invalid_map_exit(char *buffer, char *full_text, int code);
t_tile	*ft_create_tile(int x, int y, char c);
void	ft_tile_push_back(t_tile **begin_list, int x, int y, char c);
t_queue	*ft_create_queue(t_tile *tile);
void	ft_push_back_queue(t_queue **begin_list, void *data);
t_tile	*ft_find_tile(t_tile *tile, int x, int y);
t_tile	*ft_find_starting_p(t_tile *tile);

// open map
void	ft_open_map(t_tile *map);


#endif
