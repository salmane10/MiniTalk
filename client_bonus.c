/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:34:28 by slouham           #+#    #+#             */
/*   Updated: 2024/05/22 11:03:29 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	bit_sender(int pid, char byte)
{
	int				c;
	unsigned char	cmp;
	int				sig;

	c = 0;
	cmp = 128;
	while (c < 8)
	{
		if (cmp & byte)
			sig = kill(pid, SIGUSR1);
		else
			sig = kill(pid, SIGUSR2);
		if (sig == -1)
		{
			ft_putstr("FAILED SENDING SIGNAL TO THE SERVER\n");
			_exit(1);
		}
		cmp = cmp >> 1;
		c++;
		usleep(500);
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	long	pid;
	char	*message;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid <= 0 || pid > 2147483647 || ft_strlen(av[1]) > 11)
		{
			ft_putstr("Eroor: Invalid PID");
			_exit(1);
		}
		message = av[2];
		while (i < ft_strlen(message) + 1)
			bit_sender(pid, message[i++]);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
