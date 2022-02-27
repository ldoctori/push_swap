/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:15:53 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 12:15:55 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_three_a(t_stack **a, t_stack **b, char key)
{
	if ((*a)->next->next->next != 0)
		return (1);
	if ((*a)->number > (*a)->next->number
		&& (*a)->next->number > (*a)->next->next->number)
	{
		rr(a, b, key);
		ss(a, b, key);
	}
	else if ((*a)->number > (*a)->next->number
		&& (*a)->number < (*a)->next->next->number)
		ss(a, b, key);
	else if ((*a)->number > (*a)->next->number
		&& (*a)->next->number < (*a)->next->next->number)
		rr(a, b, key);
	else if ((*a)->number < (*a)->next->number
		&& (*a)->number < (*a)->next->next->number)
	{
		rrr(a, b, key);
		ss(a, b, key);
	}
	else if ((*a)->number < (*a)->next->number
		&& (*a)->number > (*a)->next->next->number)
		rrr(a, b, key);
	return (0);
}

int	is_two_a(t_stack **a, t_stack **b, char key)
{
	if ((*a)->next->next == 0 || (*a)->chunk != (*a)->next->next->chunk)
	{
		if ((*a)->number > (*a)->next->number)
			ss(a, b, key);
		return (0);
	}
	if ((*a)->next->next != 0)
		if (is_three_a(a, b, key) == 0)
			return (0);
	return (1);
}
