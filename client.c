#include "./lib/libft.h"
#include <signal.h>

int main(int argc, char **argv)
{
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
	}
	else
	{
		ft_printf("Invalid format! \nExpected: ./client <PID> phrase \n");
	}
}
