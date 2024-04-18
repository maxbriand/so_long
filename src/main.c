#include <stdio.h>



typedef struct s_params
{
	int mlx_ptr;
	int win_ptr;
} hey;

void test(void *ok)
{
	// hey *coool;

	// coool = ok;
	
	printf("%d", ((hey *)ok)->mlx_ptr);
}


int	main(void)
{
	hey doub_voiddd;
	int ok1;
	int ok2;
	
	ok1 = 1222;
	ok2 = 2444;
	doub_voiddd.mlx_ptr = ok1;
	doub_voiddd.win_ptr = ok2;

	test(&doub_voiddd);
	return (0);
}
