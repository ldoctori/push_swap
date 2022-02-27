/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:38:23 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/16 10:39:36 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_helper(const char *str, va_list ap)
{	
	char	*ptr;
	int		count;
	t_tr	tr;

	count = 0;
	while (*str)
	{	
		ptr = ft_strchr(str, '%');
		if (ptr != 0)
		{	
			ft_putnstr_fd((char *)str, 1, ptr - str);
			count += ptr - str;
			tr = ft_flag_conv_split(ap, (char *)(ptr + 1));
			count += tr.len;
			str = tr.ptr;
		}
		else
		{
			count += ft_strlen(str);
			ft_putstr_fd((char *)str, 1);
			break ;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;	

	va_start(ap, str);
	count = ft_helper(str, ap);
	va_end(ap);
	return (count);
}
