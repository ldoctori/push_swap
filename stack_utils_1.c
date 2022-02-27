/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:21:52 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 12:21:54 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	while (*s)
	{
		tmp = *s;
		*s = (*s)->next;
		free(tmp);
	}
}

t_stack	*new_stack_elem(int number)
{
	t_stack	*stack_elem;

	stack_elem = malloc(sizeof(t_stack) + 1);
	if (!stack_elem)
		return (0);
	stack_elem->number = number;
	stack_elem->chunk = 0;
	stack_elem->next = 0;
	return (stack_elem);
}

void	push_elem_top(t_stack **s, t_stack *stack_elem)
{
	if (!stack_elem)
		return ;
	if (!(*s))
	{
		*s = stack_elem;
		(*s)->next = 0;
		return ;
	}
	stack_elem->next = *s;
	*s = stack_elem;
}

void	create_stack_a(t_stack **s, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i--;
	while (i >= 0)
	{
		push_elem_top(s, new_stack_elem(ft_atoi(argv[i])));
		i--;
	}
}
