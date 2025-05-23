/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/23 18:39:21 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	
	if (ft_lstsize(*stack) < 2)
		return (false);

	head = *stack;
	next = head->next;
	
	head->next = next->next;
	next->next = head;
	*stack = next;

	return (true);
}
