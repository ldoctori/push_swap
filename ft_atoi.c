/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:14:01 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:36:39 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_helper(long number)
{
	if (number > 2147483647 || number < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
}

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if ('9' < *str || *str < '0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_SUCCESS);
		}
		number = number * 10 + (*str - '0');
		str++;
	}
	number *= sign;
	ft_atoi_helper(number);
	return ((int)number);
}
