/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <hectkctk@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:52:27 by ldoctori          #+#    #+#             */
/*   Updated: 2022/02/23 09:39:44 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				chunk;
	struct s_stack	*next;
}	t_stack;
void	is_dupl_error(t_stack **a);
void	create_stack_a(t_stack **s, char **argv);
void	free_stack(t_stack **s);
void	push_elem_top(t_stack **s, t_stack *stack_elem);
void	swap(t_stack **s);
void	rotate(t_stack **s);
void	rev_rotate(t_stack **s);
void	take_push(t_stack **s1, t_stack **s2);
void	chunk_plus(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b, char key);
void	rr(t_stack **a, t_stack **b, char key);
void	ss(t_stack **a, t_stack **b, char key);
void	free_arr_arg(char **arr_arg);
t_stack	*new_stack_elem(int number);
t_stack	*last(t_stack **s);
int		ft_atoi(const char *str);
int		check_if_sorted_a(t_stack **s);
int		check_if_sorted_b(t_stack **s);
int		buble(int *arr, int size);
int		mid_value_helper(t_stack **s, int size);
int		mid_value(t_stack **s);
int		is_three_a(t_stack **a, t_stack **b, char key);
int		is_two_a(t_stack **a, t_stack **b, char key);
int		is_two_b(t_stack **a, t_stack **b, char key);
int		smaller_than_mid(t_stack **s, int mid);
int		b_higher_a(t_stack **a, t_stack **b);
int		higher_than_mid(t_stack **s, int mid);
int		check_duplicates(t_stack **a);
int		arg_count(char **arg_arr);
char	*get_next_line(int fd);
char	**arg_arr(char **argv);
#endif
