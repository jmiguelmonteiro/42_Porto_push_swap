/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:37:20 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/24 11:31:29 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void	free_node(void *content)
{
	free(content);
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, free_node);
}

void	print_stack(t_list *stack)
{
	t_content	*content;

	while (stack)
	{
		content = (t_content *)stack->content;
		ft_printf("%d\n", content->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
