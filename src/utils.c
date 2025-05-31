/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:37:20 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 22:34:39 by josemigu         ###   ########.fr       */
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

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*before_last;

	before_last = NULL;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		before_last = lst;
		lst = lst->next;
	}
	return (before_last);
}

t_list	*stack_max_value(t_list *lst)
{
	int		max_value;
	t_list	*max_ptr;

	if (ft_lstsize(lst) < 1)
		return (NULL);
	max_value = ((t_data *)lst->content)->value;
	max_ptr = lst;
	while (lst)
	{
		if (max_value < ((t_data *)lst->content)->value)
		{
			max_value = ((t_data *)lst->content)->value;
			max_ptr = lst;
		}
		lst = lst->next;
	}
	return (max_ptr);
}

t_list	*stack_min_value(t_list *lst)
{
	int		min_value;
	t_list	*min_ptr;

	if (ft_lstsize(lst) < 1)
		return (NULL);
	min_value = ((t_data *)lst->content)->value;
	min_ptr = lst;
	while (lst)
	{
		if (min_value > ((t_data *)lst->content)->value)
		{
			min_value = ((t_data *)lst->content)->value;
			min_ptr = lst;
		}
		lst = lst->next;
	}
	return (min_ptr);
}
