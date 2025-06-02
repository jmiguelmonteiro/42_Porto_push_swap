/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_info_b_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:12:24 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/01 12:55:25 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_list *a, t_list *b)
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

void	fill_nodes_info_b_a(t_list *stack_a, t_list *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_b(stack_a, stack_b);
}
