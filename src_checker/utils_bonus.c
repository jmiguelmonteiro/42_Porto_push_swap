/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:52:04 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:52:04 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, free);
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
