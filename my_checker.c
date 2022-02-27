/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:11:22 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/20 14:19:23 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	some_double_functions(t_stack **a, t_stack **b, char *action, int len)
{
	if (ft_strncmp(action, "ss", len) == 0)
	{
		sa(a);
		sb(b);
	}
	else if (ft_strncmp(action, "rrr", len) == 0)
	{
		rra(a);
		rrb(b);
	}
	else if (ft_strncmp(action, "rr", len) == 0)
	{
		ra(a);
		rb(b);
	}
	else
	{
		ft_putstr_fd("Error!\n", 2);
		exit(EXIT_SUCCESS);
	}
}

void	some_func(t_stack **a, t_stack **b, char *action)
{
	int	len;

	len = ft_strlen(action) - 1;
	if (ft_strncmp(action, "pa", len) == 0)
		take_push(b, a);
	else if (ft_strncmp(action, "pb", len) == 0)
		take_push(a, b);
	else if (ft_strncmp(action, "sa", len) == 0)
		sa(a);
	else if (ft_strncmp(action, "sb", len) == 0)
		sb(b);
	else if (ft_strncmp(action, "ra", len) == 0)
		ra(a);
	else if (ft_strncmp(action, "rb", len) == 0)
		rb(b);
	else if (ft_strncmp(action, "rra", len) == 0)
		rra(a);
	else if (ft_strncmp(action, "rrb", len) == 0)
		rrb(b);
	else
		some_double_functions(a, b, action, len);
}

int	main_helper(t_stack **a)
{
	if (check_if_sorted_a(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**arr_arg;

	if (argc < 2)
		return (0);
	arr_arg = arg_arr(argv + 1);
	if (arg_count(arr_arg) < 2)
		return (0);
	a = 0;
	b = 0;
	create_stack_a(&a, arr_arg);
	free_arr_arg(arr_arg);
	is_dupl_error(&a);
	line = get_next_line(0);
	while (line)
	{
		some_func(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (main_helper(&a));
}
