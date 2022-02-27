/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:27:15 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 12:27:17 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp->next != 0)
		tmp = tmp->next;
	return (tmp);
}

int	smaller_than_mid(t_stack **s, int mid)
{
	t_stack	*tmp;
	int		chunk;

	tmp = *s;
	chunk = tmp->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->number < mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	chunk_plus(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->chunk++;
		tmp = tmp->next;
	}
}

int	b_higher_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_a->number < tmp_b->number)
				return (1);
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
	return (0);
}

int	higher_than_mid(t_stack **s, int mid)
{
	t_stack	*tmp;
	int		chunk;

	tmp = *s;
	chunk = tmp->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->number > mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
