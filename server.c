#include "./lib/libft.h"
#include <signal.h>

int main()
{
	ft_putnbr(getpid());

	while(1)
		pause;
}
