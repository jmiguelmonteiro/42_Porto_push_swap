/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:50:16 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:50:16 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		if (!push(stack_a, content))
			return (false);
		i--;
	}
	return (true);
}
