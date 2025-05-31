/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_info_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:12:24 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/31 17:49:34 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_nodes_a(t_list *a, t_list *b)
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
		{
			((t_data *)a->content)->target = stack_max_value(b);
			ft_printf("Biggest value: %p\n", stack_max_value(b));
		}
		a = a->next;
	}
}

static void	set_index_median(t_list *stack)
{
	int	index;
	int	median;

	index = 0;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		((t_data *)stack->content)->index = index;
		if (index < median)
			((t_data *)stack->content)->above = true;
		else
			((t_data *)stack->content)->above = false;
		stack = stack->next;
		index++;
	}
}

void	fill_nodes_info_a_b(t_list *stack_a, t_list *stack_b)
{
	(void)stack_b;
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_target_nodes_a(stack_a, stack_b);
}
