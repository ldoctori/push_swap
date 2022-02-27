/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:11:42 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/04 11:58:39 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_minus(char *str, int n, int str_len, char adjusting)
{
	char	*spaces;
	char	*new_str;
	int		i;

	i = 0;
	if (n < str_len)
		return (str);
	n -= str_len;
	spaces = malloc(n + 1);
	if (!spaces)
		return (0);
	while (i < n)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	if (adjusting == 'l')
		new_str = ft_strjoin(str, spaces);
	if (adjusting == 'r')
		new_str = ft_strjoin(spaces, str);
	free(spaces);
	free(str);
	return (new_str);
}
