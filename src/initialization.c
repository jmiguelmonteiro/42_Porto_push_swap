/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:55:13 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/23 18:00:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node(void *content)
{
	free(content);
}

bool	init_stack(int argc, char **argv, t_list **stack_a)
{
	int		i;
	t_node	*node_content;
	t_list	*node;
	
	i = argc - 1;
	while (i > 0)
	{
		node_content = ft_calloc(1, sizeof (t_node));
		if (!node_content)
			return (ft_lstclear(stack_a, del_node), false);
		node_content->value = ft_atoi(argv[i]);
		node = ft_lstnew(node_content);
		if (!node)
		{
			free(node_content);
			return (ft_lstclear(stack_a, del_node), false);
		}
		ft_lstadd_front(stack_a, node);
		i--;
	}
	return (true);
}
