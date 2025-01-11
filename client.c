#include "./lib/libft.h"
#include <signal.h>

static void	ft_send(int pid, int *binary)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (binary[i] == 1)
			kill(pid, SIGUSR1);
		else if (binary[i] == 0)
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

static void	ft_mensage(int pid, char *str)
{
	int	i;
	int	k;
	int	binary[8];

	i = 0;
	while (str[i])
	{
		k = 8;
		while (k > 0)
		{
			binary[k - 1] = str[i] % 2;
			str[i] /= 2;
			k--;
		}
		ft_send(pid, binary);
		i++;
	}
	ft_printf("message sent!\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_mensage (pid, argv[2]);
	}
	else
	{
		ft_printf("Invalid format! \nExpected: ./client <PID> phrase \n");
		return (1);
	}
	return (0);
}
