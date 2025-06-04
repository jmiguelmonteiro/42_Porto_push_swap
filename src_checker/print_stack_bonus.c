/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:51:51 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:52:27 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_stack(t_list *stack_a)
{
	t_data	*content_a;

	while (stack_a)
	{
		content_a = (t_data *)stack_a->content;
		ft_printf("p: %p ", stack_a);
		ft_printf("v: %d ", content_a->value);
		ft_printf("\n");
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}
