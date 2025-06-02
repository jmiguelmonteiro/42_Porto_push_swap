/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:12:24 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/01 22:27:06 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_data	*content;
	int		op;
	int		n_a;
	int		n_b;

	(void)stack_b;
	head = *stack_a;
	while (head)
	{
		content = head->content;
		if (content->winner)
			break ;
		head = head->next;
	}
	op = content->op;
	n_a = content->n_a;
	n_b = content->n_b;
	while (op == 0 && n_a && n_b)
	{
		rr(stack_a, stack_b);
		n_a--;
		n_b--;
	}
	while (op == 3 && n_a && n_b)
	{
		rrr(stack_a, stack_b);
		n_a--;
		n_b--;
	}
	while (n_a--)
		if (op == 0 || op == 1)
			ra(stack_a, stack_b);
	else
		rra(stack_a, stack_b);
	while (n_b--)
		if (op == 0 || op == 2)
			rb(stack_a, stack_b);
	else
		rrb(stack_a, stack_b);
	pb(stack_a, stack_b);
}

static void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int		len_a;
	int		up;
	int		down;
	t_data	*content_a;
	t_data	*content_b;

	len_a = ft_lstsize(*stack_a);
	content_b = (*stack_b)->content;
	content_a = content_b->target->content;
	up = content_a->index;
	down = len_a - content_a->index;
	if (up <= down)
		while (up--)
			ra(stack_a, stack_b);
	else
		while (down--)
			rra(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	move_min_to_top(t_list **stack_a, t_list **stack_b)
{
	t_data	*content;
	int		up;
	int		down;
	int		len;

	len = ft_lstsize(*stack_a);
	content = stack_min_value(*stack_a)->content;
	up = content->index;
	down = len - content->index;
	if (up <= down)
		while (up--)
			ra(stack_a, stack_b);
	else
		while (down--)
			rra(stack_a, stack_b);
}

void	sort_stack_turk(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if ((len-- > 3) && (!is_stack_sorted(*stack_a)))
		pb(stack_a, stack_b);
	if ((len-- > 3) && (!is_stack_sorted(*stack_a)))
		pb(stack_a, stack_b);
	while ((len-- > 3) && (!is_stack_sorted(*stack_a)))
	{
		fill_nodes_info_a_b(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_stack_simple_3(stack_a);
	while (*stack_b)
	{
		fill_nodes_info_b_a(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_index(*stack_a);
	move_min_to_top(stack_a, stack_b);
}
