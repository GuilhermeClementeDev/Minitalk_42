#include "./lib/libft.h"
#include <signal.h>

int	ft_pow(int elev)
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

void	ft_decrypt(char *arr)
{
	int	i;
	int num;

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

void	mensage(int signum)
{
	int	position_bit;
	static char	binary[9];

	position_bit = 0;
	if (binary[position_bit] != '1' && binary[position_bit] != '0')
		ft_bzero(binary, 9);
	while ((binary[position_bit] == '1' || binary[position_bit] == '0') && position_bit < 7)
		position_bit++;
	if (signum == SIGUSR1)
		binary[position_bit] = '1';
	else if (signum == SIGUSR2)
		binary[position_bit] = '0';

	position_bit++;
	if (position_bit == 8)
	{
		ft_decrypt(binary);
		ft_bzero(binary, 9);
	}
}

int main()
{
	ft_printf("Server PID %d\n", getpid());
	signal(SIGUSR1, mensage);
	signal(SIGUSR2, mensage);
	while(1)
		pause();
}
