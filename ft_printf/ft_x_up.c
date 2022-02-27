/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:31:13 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/02 09:31:15 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x_up(va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa_hex(va_arg(ap, unsigned int));
	if (!str)
		return (0);
	while (str[len])
	{
		str[len] = ft_toupper(str[len]);
		len++;
	}
	return (str);
}
