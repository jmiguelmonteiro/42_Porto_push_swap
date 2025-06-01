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

void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_data	*content;
	
	(void)stack_b;
	head = *stack_a;
	while (head)
	{
		content = head->content;
		if (content->winner)
			break;
		head = head->next;
	}
	ft_printf("Winner value: %d\n", content->value);
	if (content->cost == 0)
		pb(stack_a, stack_b);
}

void	sort_stack_turk(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if ((len-- > 3) && (!is_stack_sorted(*stack_a)))
		pb(stack_a, stack_b);
	if ((len-- > 3) && (!is_stack_sorted(*stack_a)))
		pb(stack_a, stack_b);
//	while ((len-- > 3) && (!is_stack_sorted(*stack_a)))
//	{
	fill_nodes_info_a_b(*stack_a, *stack_b);
	move_a_to_b(stack_a, stack_b);
//	}
	print_stack(*stack_a);
	print_stack(*stack_b);
//	sort_stack_simple_3(stack_a);
}
