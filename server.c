#include "./lib/libft.h"
#include <signal.h>

static int	ft_pow(int elev)
{
	int	i;
	int	num;

	num = 1;
	i = 0;
	if (elev == 0)
		return (1);
	while (i < elev)
	{
		num = num * 2;
		i++;
	}
	return (num);
}

static void	ft_decrypt(char *arr)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i] == '1')
			num += ft_pow(7 - i);
		i++;
	}
	ft_printf("%c", num);
}

static void	mensage(int signum)
{
	int			k;
	static char	binary[9];

	k = 0;
	if (binary[k] != '1' && binary[k] != '0')
		ft_bzero(binary, 9);
	while ((binary[k] == '1' || binary[k] == '0') && k < 7)
		k++;
	if (signum == SIGUSR1)
		binary[k] = '1';
	else if (signum == SIGUSR2)
		binary[k] = '0';
	k++;
	if (k == 8)
	{
		ft_decrypt(binary);
		ft_bzero(binary, 9);
	}
}

int	main(void)
{
	ft_printf("Server PID %d\n", getpid());
	signal(SIGUSR1, mensage);
	signal(SIGUSR2, mensage);
	while (1)
		pause();
}
