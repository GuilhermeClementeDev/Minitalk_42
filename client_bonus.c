#include "./lib/libft.h"
#include <signal.h>

static void	handler_bit(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Mensage Recevied from server !!!\n");
}

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
		pause();
		i++;
	}
}

static void	ft_mensage(int pid, char *str)
{
	int				i;
	int				k;
	int				binary[8];
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		k = 8;
		c = str[i];
		while (k > 0)
		{
			binary[k - 1] = c % 2;
			c /= 2;
			k--;
		}
		ft_send(pid, binary);
		i++;
	}
	k = 0;
	while (k < 8)
		binary[k++] = 0;
	if (str[0])
		ft_send(pid, binary);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		signal(SIGUSR1, handler_bit);
		signal(SIGUSR2, handler_bit);
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
