/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:12:24 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/31 17:07:25 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
	sort_stack_simple_3(stack_a);
	print_stacks(*stack_a, *stack_b);
}
