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

int	min_op_43(int a[4][3])
{
	int	op;
	int	i;

	op = 0;
	i = 0;
	while (i < 4)
	{
		if (a[i][2] < a[op][2])
			op = i;
		i++;
	}
	return (op);
}

int	max_int(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

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
