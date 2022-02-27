/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:11:19 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/04 13:20:52 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_flag_minus = 0;
int	g_flag_zero = 0;

char	*ft_isflag_helper(char *pp)
{
	if (*pp > 48 && *pp < 57)
	{
		g_flag_minus = -1;
		return (pp);
	}
	while (ft_isfunc(pp) == -1 && (*pp <= 48 || *pp > 57))
	{	
		if (*pp == '-')
			g_flag_minus = 1;
		else if (*pp == '0')
			g_flag_zero = 1;
		pp++;
	}
	return (pp);
}

char	*ft_isflag(char *pp, char *str, int str_len)
{
	pp = ft_isflag_helper(pp);
	if (g_flag_minus == 1)
		return (ft_flag_minus(str, ft_atoi(pp), str_len, 'l'));
	if (g_flag_zero == 1)
		return (ft_flag_zero(str, ft_atoi(pp)));
	if (g_flag_minus == -1)
		return (ft_flag_minus(str, ft_atoi(pp), str_len, 'r'));
	return (str);
}
