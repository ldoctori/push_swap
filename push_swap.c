/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:30:26 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 11:30:29 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_t_l_helper(t_stack **a, t_stack **b, int mid, int chunk)
{
	while ((check_if_sorted_a(a) != 0 && smaller_than_mid(a, mid) != 0)
		|| b_higher_a(a, b) != 0)
	{
		while ((*a)->number >= mid && (*a)->chunk == chunk)
			rr(a, b, 'a');
		if ((*a)->number < (*a)->next->number
			&& (*a)->number < last(a)->number)
			pb(a, b);
		else
		{
			if ((*a)->number > (*a)->next->number)
				ss(a, b, 'a');
			else if ((*a)->number > last(a)->number)
				rrr(a, b, 'a');
			else
				pb(a, b);
		}
	}
}

void	all_that_lower(t_stack **a, t_stack **b, int key)
{
	int	mid;
	int	chunk;

	if (check_if_sorted_a(a) == 0)
		return ;
	if (is_two_a(a, b, 'a') == 0)
		return ;
	mid = mid_value(a);
	chunk = (*a)->chunk;
	all_t_l_helper(a, b, mid, chunk);
	if (key == 0)
		chunk_plus(a);
	else
		while (last(a)->chunk == chunk)
			rrr(a, b, 'a');
	return (all_that_lower(a, b, key));
}

void	all_t_h_helper(t_stack **a, t_stack **b, int mid, int chunk)
{
	while ((*b && check_if_sorted_b(b) != 0
			&& higher_than_mid(b, mid) != 0) || b_higher_a(a, b) != 0)
	{
		while ((*b)->number <= mid && (*b)->chunk == chunk)
			rr(a, b, 'b');
		if ((*b)->number > (*b)->next->number && (*b)->number > last(b)->number)
			pa(a, b);
		else if ((*b)->number < (*b)->next->number
			&& (*b)->number > last(b)->number)
			ss(a, b, 'b');
		else if ((*b)->number < (*b)->next->number
			|| (*b)->number < last(b)->number)
			rrr(a, b, 'b');
	}
}

void	all_that_higher(t_stack **a, t_stack **b)
{
	int	mid;
	int	chunk;

	if (*b == 0)
		return ;
	chunk = (*b)->chunk;
	if (check_if_sorted_b(b) == 0 || is_two_b(a, b, 'b') == 0)
	{
		while (*b && (*b)->chunk == chunk)
			pa(a, b);
		return ;
	}
	mid = mid_value(b);
	all_t_h_helper(a, b, mid, chunk);
	while (*b && chunk != 0 && last(b)->chunk == chunk)
		rrr(a, b, 'b');
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arr_arg;

	a = 0;
	b = 0;
	if (argc < 2)
		return (0);
	arr_arg = arg_arr(argv + 1);
	if (arg_count(arr_arg) < 2)
		return (0);
	create_stack_a(&a, arr_arg);
	free_arr_arg(arr_arg);
	is_dupl_error(&a);
	all_that_lower(&a, &b, 0);
	while (b)
	{
		all_that_higher(&a, &b);
		all_that_lower(&a, &b, 1);
	}
	free_stack(&a);
	return (0);
}
