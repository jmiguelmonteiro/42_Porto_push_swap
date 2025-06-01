/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:55:13 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 15:31:12 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	init_stack(int argc, char **argv, t_list **stack_a)
{
	int		i;
	t_data	*content;

	i = argc - 1;
	while (i > 0)
	{
		content = malloc(1 * sizeof (*content));
		if (!content)
			return (free_stack(stack_a), false);
		content->value = ft_atoi(argv[i]);
		content->index = 0;
		content->target = NULL;
		content->op = 0;
		content->cost = 0;
		content->winner = false;
		if (!push(stack_a, content))
			return (false);
		i--;
	}
	return (true);
}
