/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:22:12 by slouham           #+#    #+#             */
/*   Updated: 2024/05/09 11:48:25 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    bit_sender(int  pid, char   byte)
{
    int c;
    int sig;

    c = 0;
    unsigned char cmp = 128;
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


size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int     main(int ac , char **av)
{
    int     pid;
    char    *message;
    
    if (ac == 3)
    {
        int i;
        
        i = 0;
        pid = ft_atoi(av[1]);
        if (pid <= 0 || pid > 2147483647 || ft_strlen(av[1]) > 11)
        {
            ft_putstr("Eroor: Invalid PID");
            _exit(1);
        }
        message = av[2];
        while (i < ft_strlen(message) + 1 )
        {
            bit_sender(pid, message[i++]);
            usleep(42);
        }
    }
    else
        write(1, "\n", 1);
    return(0);
}