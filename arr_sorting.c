/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:50:47 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 10:53:13 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	buble(int *arr, int size)
{
	int	i;
	int	j;
	int	buff;

	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
			}
			j++;
		}
		i--;
	}
	buff = arr[size / 2];
	free(arr);
	return (buff);
}

int	mid_value_helper(t_stack **s, int size)
{
	int		*arr;
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = *s;
	arr = malloc(sizeof(int) * size);
	while (count < size)
	{
		arr[count] = tmp->number;
		count++;
		tmp = tmp->next;
	}
	return (buble(arr, size));
}

int	mid_value(t_stack **s)
{
	t_stack	*tmp;
	int		i;
	int		chunk;

	i = 0;
	tmp = *s;
	chunk = tmp->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		tmp = (tmp)->next;
		i++;
	}
	return (mid_value_helper(s, i));
}
