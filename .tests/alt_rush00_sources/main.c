#include "../../ex00/include/ft_utils.h"

void	rush(int a, int b);

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	int w = ft_atoi(argv[1]);
	int h = ft_atoi(argv[2]);

	rush(w, h);
	return (0);
}
