/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:30:02 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/02 09:30:03 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(va_list ap)
{
	char			*buff;

	buff = ft_itoa_unsigned(va_arg(ap, unsigned int));
	if (!buff)
		return (0);
	return (buff);
}
