/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:22:14 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/04 11:02:19 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isfunc(char *ptr)
{
	if (*ptr == 'c')
		return (0);
	if (*ptr == 's')
		return (1);
	if (*ptr == 'i' || *ptr == 'd')
		return (2);
	if (*ptr == 'u')
		return (3);
	if (*ptr == 'x')
		return (4);
	if (*ptr == 'X')
		return (5);
	if (*ptr == 'p')
		return (6);
	if (*ptr == '%')
		return (7);
	else
		return (-1);
}

char	*ft_func_arr(va_list ap, char *ptr)
{	
	int		k;
	char	*(*func[9])(va_list);

	func[0] = ft_c;
	func[1] = ft_s;
	func[2] = ft_id;
	func[3] = ft_u;
	func[4] = ft_x;
	func[5] = ft_x_up;
	func[6] = ft_p;
	if (*ptr == '%')
		return (ft_percent());
	k = ft_isfunc(ptr);
	if (k == -1)
		return (NULL);
	return (func[k](ap));
}
