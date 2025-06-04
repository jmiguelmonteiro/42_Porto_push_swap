/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:23:52 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 22:36:22 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_data
{
	int				value;
	int				index;
	struct s_list	*target;
	int				op;
	int				n_a;
	int				n_b;
	int				cost;
	bool			winner;
}	t_data;

typedef struct s_operation
{
	int				op;
	int				n_a;
	int				n_b;
}	t_operation;

void	check_arguments(int argc, char **argv);
void	ft_error(void);

bool	init_stack(int argc, char **argv, t_list **stack_a);
void	free_stack(t_list **stack);
int		max_int(int a, int b);
int		min_op_43(int a[4][3]);
void	print_stack(t_list *stack_a);
t_list	*ft_lstbeforelast(t_list *lst);

bool	is_stack_sorted(t_list *stack);
void	sort_stack(t_list **stack);
void	sort_stack_simple(t_list **stack);
void	sort_stack_simple_3(t_list **stack_a);
void	sort_stack_radix(t_list **stack_a, t_list **stack_b);
void	sort_stack_turk(t_list **stack_a, t_list **stack_b);
t_list	*stack_min_value(t_list *lst);
t_list	*stack_max_value(t_list *lst);
void	set_index(t_list *stack);
void	fill_nodes_info_a_b(t_list *stack_a, t_list *stack_b);
void	fill_nodes_info_b_a(t_list *stack_a, t_list *stack_b);

bool	push(t_list **stack, t_data *content);
t_data	*pop(t_list **stack);
t_data	*peek(t_list *stack);
void	sa(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
