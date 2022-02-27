/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:24:53 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/02 09:24:55 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p(va_list ap)
{	
	char	*buff;
	char	preffix[3];
	char	*str;

	preffix[0] = '0';
	preffix[1] = 'x';
	preffix[2] = '\0';
	buff = ft_itoa_hex(va_arg(ap, unsigned long int));
	if (!buff)
		return (0);
	str = ft_strjoin((const char *)preffix, (const char *)buff);
	if (!str)
		return (0);
	free(buff);
	return (str);
}
