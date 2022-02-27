/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:01:20 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 11:01:23 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted_a(t_stack **s)
{
	t_stack	*tmp;
	int		chunk;

	tmp = *s;
	chunk = tmp->chunk;
	while (tmp->next != 0 && tmp->chunk == chunk)
	{
		if (tmp->number > tmp->next->number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_if_sorted_b(t_stack **s)
{
	t_stack	*tmp;
	int		chunk;

	tmp = *s;
	chunk = tmp->chunk;
	while (tmp->next != 0 && tmp->chunk == chunk)
	{
		if (tmp->number < tmp->next->number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
