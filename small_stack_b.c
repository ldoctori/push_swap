/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:05:20 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 12:09:59 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_tbch_helper(t_stack **a, t_stack **b, char key)
{
	if ((*b)->number < (*b)->next->number
		&& (*b)->number < (*b)->next->next->number)
	{
		rr(a, b, key);
		if ((*b)->number < (*b)->next->number)
			ss(a, b, key);
		pa(a, b);
		pa(a, b);
		rrr(a, b, key);
	}
	else if (((*b)->number < (*b)->next->number
			&& (*b)->number > (*b)->next->next->number)
		|| ((*b)->number > (*b)->next->number
			&& (*b)->number < (*b)->next->next->number))
	{
		rr(a, b, key);
		if ((*b)->number < (*b)->next->number)
			ss(a, b, key);
		pa(a, b);
		rrr(a, b, key);
	}
}

int	is_three_b_chunk(t_stack **a, t_stack **b, char key)
{
	if ((*b)->chunk != (*b)->next->chunk
		|| (*b)->chunk != (*b)->next->next->chunk
		|| (*b)->chunk == (*b)->next->next->next->chunk)
		return (1);
	if ((*b)->number > (*b)->next->number
		&& (*b)->next->number < (*b)->next->next->number)
	{
		rr(a, b, key);
		ss(a, b, key);
		rrr(a, b, key);
	}
	else
		is_tbch_helper(a, b, key);
	return (0);
}

int	is_three_b(t_stack **a, t_stack **b, char key)
{
	if ((*b)->next->next->next != 0)
		return (1);
	if ((*b)->number < (*b)->next->number
		&& (*b)->next->number < (*b)->next->next->number)
	{
		rr(a, b, key);
		ss(a, b, key);
	}
	else if ((*b)->number < (*b)->next->number
		&& (*b)->number > (*b)->next->next->number)
		ss(a, b, key);
	else if ((*b)->number < (*b)->next->number
		&& (*b)->next->number > (*b)->next->next->number)
		rr(a, b, key);
	else if ((*b)->number > (*b)->next->number
		&& (*b)->number > (*a)->next->next->number)
	{
		rrr(a, b, key);
		ss(a, b, key);
	}
	else if ((*b)->number > (*b)->next->number
		&& (*b)->number < (*b)->next->next->number)
		rrr(a, b, key);
	return (0);
}

int	is_two_b(t_stack **a, t_stack **b, char key)
{
	if ((*b)->next->next == 0 || (*b)->chunk != (*b)->next->next->chunk)
	{
		if ((*b)->number < (*b)->next->number)
			ss(a, b, key);
		return (0);
	}
	if ((*a)->next->next != 0)
		if (is_three_b(a, b, key) == 0 || is_three_b_chunk(a, b, key) == 0)
			return (0);
	return (1);
}
