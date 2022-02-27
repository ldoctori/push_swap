/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:29:26 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/02 09:29:38 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_null(void)
{
	char	*null;

	null = malloc(6);
	if (!null)
		return (0);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	return (null);
}

char	*ft_s(va_list ap)
{
	char	*buff;
	char	*str;
	int		len;
	int		i;

	buff = va_arg(ap, char *);
	if (buff == NULL)
		return (ft_null());
	len = ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
