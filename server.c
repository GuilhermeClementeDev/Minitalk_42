/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:16:25 by guclemen          #+#    #+#             */
/*   Updated: 2025/01/15 08:16:28 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_decrypt(int *arr)
{
	int				i;
	unsigned int	num;

	num = 0;
	i = 0;
	while (i < 8)
	{
		if (arr[i] == 1)
			num += ft_pow(7 - i);
		i++;
	}
	if (num == 0)
		write(1, "\n", 1);
	else
		write(1, &num, 1);
}

static void	mensage(int sig)
{
	static int	position_bit = 0;
	static int	binary[8];

	if (sig == SIGUSR1)
		binary[position_bit] = 1;
	else if (sig == SIGUSR2)
		binary[position_bit] = 0;
	position_bit++;
	if (position_bit == 8)
	{
		ft_decrypt(binary);
		position_bit = 0;
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
