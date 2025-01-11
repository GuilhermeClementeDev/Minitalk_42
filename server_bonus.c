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
	return num;
}

void	ft_decrypt(int *arr)
{
	int	i;
	int num;

	num = 0;
	i = 0;
	while (i < 8)
	{
		if (arr[i] == 1)
			num += ft_pow(7 - i);
		i++;
	}
	ft_printf("%c", num);

}

void	mensage(int sig, siginfo_t	*siginfo, void *context)
{
	static int	position_bit = 0;
	static int	binary[8];

	(void)context;
	if (sig == SIGUSR1)
	{
		binary[position_bit] = 1;
		kill(siginfo->si_pid, SIGUSR1);
	}
	else
	{
		binary[position_bit] = 0;
		kill(siginfo->si_pid, SIGUSR1);
	}
	position_bit++;
	if (position_bit == 8)
	{
		ft_decrypt(binary);
		position_bit = 0;
	}
}

int main()
{
	struct sigaction	st;

	sigemptyset(&st.sa_mask);
	st.sa_sigaction = &mensage;
	st.sa_flags = SA_SIGINFO;

	ft_printf("Server PID %d\n", getpid());
	sigaction(SIGUSR1, &st, NULL);
	sigaction(SIGUSR2, &st, NULL);
	while(1)
		pause();
}