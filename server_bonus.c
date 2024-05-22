/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:35:20 by slouham           #+#    #+#             */
/*   Updated: 2024/05/10 17:18:50 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	hundler(int signal)
{
	static int	c;
	static char	chr;

	if (signal == SIGUSR1)
		chr = (chr << 1) | 1;
	else if (signal == SIGUSR2)
		chr = (chr << 1);
	c++;
	if (c == 8)
	{
		write(1, &chr, 1);
		c = 0;
		chr = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, &hundler);
	signal(SIGUSR2, &hundler);
	while (1)
		;
}
