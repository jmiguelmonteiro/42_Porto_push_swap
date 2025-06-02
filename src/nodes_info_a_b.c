/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_info_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:12:24 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/01 12:55:25 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_winner(t_list *stack)
{
	long	winner_cost;
	t_list	*winner;

	winner_cost = ((t_data *)stack->content)->cost;
	winner = stack;
	while (stack)
	{
		if (((t_data *)stack->content)->cost < winner_cost)
		{
			winner_cost = ((t_data *)stack->content)->cost;
			winner = stack;
		}
		stack = stack->next;
	}
	((t_data *)winner->content)->winner = true;
}

static void	set_cost_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;
	int	cost[4][3];

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		cost[0][0] = ((t_data *)a->content)->index;
		cost[1][0] = cost[0][0];
		cost[2][0] = len_a - ((t_data *)a->content)->index;
		cost[3][0] = cost[2][0];
		cost[0][1] = ((t_data *)((t_data *)a->content)->target->content)->index;
		cost[1][1] = len_b
			- ((t_data *)((t_data *)a->content)->target->content)->index;
		cost[2][1] = cost[0][1];
		cost[3][1] = cost[1][1];
		cost[0][2] = max_int(cost[0][0], cost[0][1]);
		cost[1][2] = cost[1][0] + cost[1][1];
		cost[2][2] = cost[2][0] + cost[2][1];
		cost[3][2] = max_int(cost[3][0], cost[3][1]);
		((t_data *)a->content)->op = min_op_43(cost);
		((t_data *)a->content)->n_a = cost[min_op_43(cost)][0];
		((t_data *)a->content)->n_b = cost[min_op_43(cost)][1];
		((t_data *)a->content)->cost = cost[min_op_43(cost)][2];
		a = a->next;
	}
}

static void	set_target_a(t_list *a, t_list *b)
{
	t_list	*target;
	t_list	*hb;
	long	best_match_value;

	while (a)
	{
		best_match_value = LONG_MIN;
		hb = b;
		while (hb)
		{
			if (((t_data *)hb->content)->value < ((t_data *)a->content)->value
				&& ((t_data *)hb->content)->value > best_match_value)
			{
				best_match_value = ((t_data *)hb->content)->value;
				target = hb;
			}
			hb = hb->next;
		}
		if (best_match_value != LONG_MIN)
			((t_data *)a->content)->target = target;
		else
			((t_data *)a->content)->target = stack_max_value(b);
		a = a->next;
	}
}

void	set_index(t_list *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		((t_data *)stack->content)->index = index;
		stack = stack->next;
		index++;
	}
}

void	fill_nodes_info_a_b(t_list *stack_a, t_list *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost_a(stack_a, stack_b);
	set_winner(stack_a);
}
