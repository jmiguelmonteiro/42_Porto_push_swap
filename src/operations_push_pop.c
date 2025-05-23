/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_pop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/23 19:12:17 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*push(t_list **stack, t_node)
{
	t_list	*head;
	t_list	*next;
	
	if (ft_lstsize(*stack) < 2)
		return ;

	head = *stack;
	next = head->next;
	
	head->next = next->next;
	next->next = head;
	*stack = next;
}
