/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farr_declare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:09:30 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/16 11:11:56 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_check(int *str_len, char *ptr, char *str_buff)
{
	if (*ptr == 'c' && *str_buff == 0)
	{
		str_len++;
		ft_putchar_fd('\0', 1);
	}
}

t_tr	ft_conv_helper(va_list ap, char *ptr, char *str, char *str_buff)
{
	int		str_len;
	char	*pp;
	t_tr	tr;

	pp = ptr;
	tr.len = 0;
	while (ft_isfunc(ptr) == -1)
		ptr++;
	tr.ptr = ptr;
	str = ft_func_arr(ap, ptr);
	if (!str)
		return (tr);
	str_buff = str;
	str_len = ft_strlen(str);
	ft_c_check(&str_len, ptr, str_buff);
	str = ft_isflag(pp, str, str_len);
	ft_putstr_fd(str, 1);
	if (!str)
		return (tr);
	tr.len = ft_strlen(str);
	if (*ptr == 'c' && *str_buff == 0 && *str == '\0')
		tr.len++;
	free(str);
	return (tr);
}

t_tr	ft_flag_conv_split(va_list ap, char *ptr)
{	
	char	*str;
	char	*str_buff;

	str = 0;
	str_buff = 0;
	return (ft_conv_helper(ap, ptr, str, str_buff));
}
