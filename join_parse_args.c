/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_parse_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:38:57 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/23 09:39:00 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr_arg(char **arr_arg)
{
	char	**tmp1;
	char	*tmp2;

	tmp1 = arr_arg;
	while (*tmp1)
	{
		tmp2 = *tmp1;
		tmp1++;
		free(tmp2);
	}
	free(arr_arg);
}

char	**arg_arr(char **argv)
{
	char	*str;
	char	*tmp;
	char	**arr_arg;

	str = malloc(1);
	str[0] = '\0';
	while (*argv)
	{
		tmp = str;
		str = ft_strjoin(tmp, *argv);
		free(tmp);
		tmp = str;
		str = ft_strjoin(tmp, " ");
		free(tmp);
		argv++;
	}
	arr_arg = ft_split(str, ' ');
	free(str);
	return (arr_arg);
}

int	arg_count(char **arg_arr)
{
	int	count;

	count = 0;
	while (*arg_arr)
	{
		arg_arr++;
		count++;
	}
	return (count);
}
