#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == ' ' && (argv[1][i + 1] != ' ' || argv[1][i + 1] != '\0'))
				write(1, "   ", 3);
			else if (argv[1][i] != ' ')
				write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
