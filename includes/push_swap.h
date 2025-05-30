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

typedef struct s_content
{
	int	value;
	int	index;
}	t_content;

void		check_arguments(int argc, char **argv);
void		ft_error(void);

bool		init_stack(int argc, char **argv, t_list **stack_a);
void		free_node(void *content);
void		free_stack(t_list **stack);
void		print_stacks(t_list *stack_a, t_list *stack_b);
void		print_stack(t_list *stack_a);
t_list		*ft_lstbeforelast(t_list *lst);

bool		is_stack_sorted(t_list *stack);
void		sort_stack(t_list **stack);
void		sort_stack_simple(t_list **stack);
void		sort_stack_simple_3(t_list **stack_a);
void		sort_stack_full(t_list **stack_a);
void		sort_stack_radix(t_list **stack_a);

bool		push(t_list **stack, t_content *content);
t_content	*pop(t_list **stack);
t_content	*peek(t_list *stack);

void		sa(t_list **stack_a, t_list **stack_b);
void		sb(t_list **stack_a, t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a, t_list **stack_b);
void		rb(t_list **stack_a, t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a, t_list **stack_b);
void		rrb(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);

void		operations_tests(t_list **stack_a, t_list **stack_b);

#endif
