/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:36:15 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/30 16:15:59 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_content	*content_a;
	t_content	*content_b;

	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			content_a = (t_content *)stack_a->content;
			stack_a = stack_a->next;
			ft_printf("%d ", content_a->value);
		}
		else
			ft_printf(". ");
		if (stack_b)
		{
			content_b = (t_content *)stack_b->content;
			stack_b = stack_b->next;
			ft_printf("%d\n", content_b->value);
		}
		else
			ft_printf(".\n");
	}
	ft_printf("- -\na b\n\n");
}

void	print_stack(t_list *stack_a)
{
	t_content	*content_a;

	while (stack_a)
	{
		content_a = (t_content *)stack_a->content;
		stack_a = stack_a->next;
		ft_printf("v: %d - i: %d\n", content_a->value, content_a->index);
	}
	ft_printf("\n");
}
