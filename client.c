/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:48:28 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/24 11:48:58 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char *str_to_send)
{
	unsigned char	c;
	int				i;

	while (*str_to_send)
	{
		c = *str_to_send;
		i = 7;
		while (i >= 0)
		{
			if (((c >> i) & 1) == 0)
			{
				kill(pid, SIGUSR1);
			}
			else if (((c >> i) & 1) == 1)
			{
				kill(pid, SIGUSR2);
			}
			usleep(150);
			i--;
		}
		str_to_send++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_signal(ft_atoi(argv[1]), (unsigned char *)argv[2]);
	}
	else
		write(1, "Error, write the correct number of arguments.\n", 46);
}
