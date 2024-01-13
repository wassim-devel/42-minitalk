/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:30:31 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/24 11:32:48 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_binary_to_char(int sig)
{
	static int	bit = 0;
	static int	i = 0;

	if (sig == SIGUSR2)
		i = i | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Waiting for a signal ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_handler = &convert_binary_to_char;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(10);
	}
	return (0);
}
