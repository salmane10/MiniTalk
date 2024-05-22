/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:51:27 by slouham           #+#    #+#             */
/*   Updated: 2024/05/22 11:04:05 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h> // for exit()
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);

#endif