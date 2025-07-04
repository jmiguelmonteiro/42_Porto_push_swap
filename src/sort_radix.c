/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:12:24 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/31 18:39:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_index(t_list *stack_a)
{
	t_list	*lst_out;
	t_list	*lst_in;
	int		i;

	lst_out = stack_a;
	while (lst_out)
	{
		i = 0;
		lst_in = stack_a;
		while (lst_in)
		{
			if (((t_data *)lst_in->content)->value
				< ((t_data *)lst_out->content)->value)
				i++;
			lst_in = lst_in->next;
		}
		((t_data *)lst_out->content)->index = i;
		lst_out = lst_out->next;
	}
}

void	sort_stack_radix(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	populate_index(*stack_a);
	size = ft_lstsize(*stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
			if ((((peek(*stack_a)->index) >> i) & 1) == 1)
				ra(stack_a, NULL);
		else
			pb(stack_a, stack_b);
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
