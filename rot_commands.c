/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:53:17 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 11:53:18 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	if (*a && *a != last(a))
		rotate(a);
}

void	rb(t_stack **b)
{
	if (*b && *b != last(b))
		rotate(b);
}

void	rra(t_stack **a)
{
	if (*a && *a != last(a))
		rev_rotate(a);
}

void	rrb(t_stack **b)
{
	if (*b && *b != last(b))
		rev_rotate(b);
}
