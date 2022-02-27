/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:17:28 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 12:17:30 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !(*s) || !(*s)->next)
		return ;
	tmp = *s;
	*s = tmp->next;
	tmp->next = (*s)->next;
	(*s)->next = tmp;
}

void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*ptr;

	ptr = *s;
	tmp = (*s)->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *s;
	(*s)->next = 0;
	*s = tmp;
}

void	rev_rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*ptr;

	ptr = *s;
	while (ptr->next->next)
		ptr = ptr->next;
	tmp = ptr->next;
	ptr->next = 0;
	tmp->next = *s;
	*s = tmp;
}

void	take_push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	if (!(*s1))
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	push_elem_top(s2, tmp);
}
