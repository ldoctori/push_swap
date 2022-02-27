/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:17:52 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/03 09:17:54 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_iszerostart(char *p_str, char *zeroes, int n)
{	
	int	i;

	i = 0;
	zeroes[i] = '\0';
	if (*p_str == '-' && n > 0)
	{
		n++;
		ft_strlcat(zeroes, "-", n);
		p_str++;
		i = 1;
	}
	if (*p_str == '0' && *(p_str + 1) == 'x' && n > 0)
	{
		n += 2;
		p_str += 2;
		ft_strlcat(zeroes, "0x", n);
		i = 2;
	}
	while (i < n)
	{
		zeroes[i] = '0';
		i++;
	}
	zeroes[i] = '\0';
	return (p_str);
}

char	*ft_flag_zero(char *str, int n)
{
	char	*zeroes;
	char	*new_str;
	int		str_len;

	str_len = ft_strlen(str);
	n -= str_len;
	if (n < 0)
		n = 0;
	zeroes = malloc(n + 1);
	if (!zeroes)
		return (0);
	new_str = ft_strjoin(zeroes, ft_iszerostart(str, zeroes, n));
	free(zeroes);
	free(str);
	return (new_str);
}
