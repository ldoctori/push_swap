/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:30:32 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/02 09:30:38 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x(va_list ap)
{
	char			*buff;

	buff = ft_itoa_hex((unsigned long int)va_arg(ap, unsigned int));
	if (!buff)
		return (0);
	return (buff);
}
