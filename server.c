/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:22:33 by slouham           #+#    #+#             */
/*   Updated: 2024/05/09 12:34:50 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void hundler(int signal)
{
    static int  c;
    static char str;
    
    if (signal == SIGUSR1)
        str = (str << 1) | 1;
    else if (signal == SIGUSR2)
        str = (str << 1);
    c++;
    if (c == 8)
    {
        write(1, &str, 1);
        c = 0;
        str = 0;
    }
}
int main()
{
    int pid;
    
    pid = getpid();
    ft_putnbr(pid);
    ft_putchar('\n');
    signal(SIGUSR1, &hundler);
    signal(SIGUSR2, &hundler);
    while(1);
}
