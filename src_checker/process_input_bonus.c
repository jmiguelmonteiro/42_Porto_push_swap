/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:57:50 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 18:05:27 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	process_input(t_list **stack_a, t_list **stack_b, char *input)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		sa(stack_a, stack_b);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		sb(stack_a, stack_b);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(input, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		ra(stack_a, stack_b);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		rb(stack_a, stack_b);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		rra(stack_a, stack_b);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		rrb(stack_a, stack_b);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else
		return (false);
	return (true);
}

void	get_input(t_list **stack_a, t_list **stack_b)
{
	char	*input;

	while (true)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (!process_input(stack_a, stack_b, input))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			free(input);
			ft_error();
		}
		free(input);
	}
	free(input);
}
