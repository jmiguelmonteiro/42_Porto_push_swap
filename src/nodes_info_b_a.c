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
	t_list	*ha;
	long	best_match_value;

	best_match_value = LONG_MAX;
	ha = a;
	while (ha)
	{
		if (((t_data *)ha->content)->value > ((t_data *)b->content)->value
			&& ((t_data *)ha->content)->value < best_match_value)
		{
			best_match_value = ((t_data *)ha->content)->value;
			target = ha;
		}
		ha = ha->next;
	}
	if (best_match_value != LONG_MAX)
		((t_data *)b->content)->target = target;
	else
		((t_data *)b->content)->target = stack_min_value(a);
}

void	fill_nodes_info_b_a(t_list *stack_a, t_list *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_b(stack_a, stack_b);
}
