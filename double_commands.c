/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:55:17 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 10:56:16 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, char key)
{
	if (*a && *b && (*a)->next && (*b)->next
		&& (*b)->number < (*b)->next->number
		&& (*a)->number > (*a)->next->number)
	{
		sa(a);
		sb(b);
		ft_printf("ss\n");
	}
	else
	{
		if (key == 'a')
		{
			sa(a);
			ft_printf("sa\n");
		}
		else if (key == 'b')
		{
			sb(b);
			ft_printf("sb\n");
		}
	}
}

void	rr(t_stack **a, t_stack **b, char key)
{
	if (key == 'a')
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if (key == 'b')
	{
		rb(b);
		ft_printf("rb\n");
	}
}

void	rrr(t_stack **a, t_stack **b, char key)
{
	if (*a && *b && last(a)->number < (*a)->number
		&& last(b)->number > (*b)->number)
	{
		rra(a);
		rrb(b);
		ft_printf("rrr\n");
	}
	else
	{
		if (key == 'a')
		{
			rra(a);
			ft_printf("rra\n");
		}
		else if (key == 'b')
		{
			rrb(b);
			ft_printf("rrb\n");
		}
	}
}
