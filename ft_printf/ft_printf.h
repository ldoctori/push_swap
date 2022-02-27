/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:27:21 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/04 12:06:26 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_tr
{
	int		len;
	char	*ptr;
}	t_tr;

int		ft_printf(const char *str, ...);
t_tr	ft_flag_conv_split(va_list ap, char *ptr);
char	*ft_c(va_list ap);
char	*ft_func_arr(va_list ap, char *ptr);
char	*ft_s(va_list ap);
char	*ft_id(va_list ap);
char	*ft_u(va_list ap);
char	*ft_x(va_list ap);
char	*ft_x_up(va_list ap);
char	*ft_p(va_list ap);
char	*ft_percent(void);
int		ft_isfunc(char *ptr);
char	*ft_isflag(char *ptr, char *str, int str_len);
char	*ft_flag_minus(char *str, int n, int str_len, char adjusting);
char	*ft_flag_zero(char *str, int n);

#endif
