#include "so_long.h"

static void ft_exit_validation_rectangular(void)
{
	//(void) full_text;
	//free(full_text);
	ft_exit_error_message("Map is not rectangular");
}

static int	ft_len_ref(char *full_text)
{
	int ref;
	
	ref = 0;
	while (*full_text)
	{
		ref++;
		if (*full_text)
			break;
		full_text++;
	}
	return(ref);
}

void	ft_validation_rectangular(char *full_text)
{
	int ref;
	int	candidate;
	
	ref = ft_len_ref(full_text);
	candidate = 0;
	while (*full_text)
	{
		candidate++;
		if (*full_text == '\n')
		{
			if (candidate != ref)
				ft_exit_validation_rectangular();
			candidate = 0;
		}
		full_text++;
	}
}
