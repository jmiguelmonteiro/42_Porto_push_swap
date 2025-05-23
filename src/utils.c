/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:37:20 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/23 18:41:14 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 7);
	exit (0);
	
}

void	print_stack(t_list *stack)
{
	t_node	*node;

	ft_printf("\n");
	while (stack)
	{
		node = (t_node *)stack->content;
		ft_printf("%d\n", node->value);
		stack = stack->next;
	}
}
