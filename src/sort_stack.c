/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:55:49 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/31 20:13:36 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head && head->next)
	{
		if (((t_data *)head->content)->value
			> ((t_data *)head->next->content)->value)
			return (false);
		head = head->next;
	}
	return (true);
}

void	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) <= 3)
		sort_stack_simple(stack_a);
	else
		sort_stack_turk(stack_a, &stack_b);
	free_stack(&stack_b);
}

void	sort_stack_simple(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, NULL);
	else
		sort_stack_simple_3(stack_a);
}

void	sort_stack_simple_3(t_list **stack_a)
{
	t_list	*head;
	int		num[3];

	if ((ft_lstsize(*stack_a) != 3) || is_stack_sorted(*stack_a))
		return ;
	head = *stack_a;
	num[0] = ((t_data *)head->content)->value;
	num[1] = ((t_data *)head->next->content)->value;
	num[2] = ((t_data *)head->next->next->content)->value;
	if (num[0] > num[1] && num[1] > num[2])
	{
		sa(stack_a, NULL);
		rra(stack_a, NULL);
	}
	else if (num[0] < num[2] && num[2] < num[1])
	{
		rra(stack_a, NULL);
		sa(stack_a, NULL);
	}
	else if (num[0] > num[2] && num[2] > num[1])
		ra(stack_a, NULL);
	else if (num[0] > num[1])
		sa(stack_a, NULL);
	else
		rra(stack_a, NULL);
}
