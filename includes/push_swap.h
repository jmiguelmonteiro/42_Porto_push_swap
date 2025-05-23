/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:23:52 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/23 19:01:09 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdbool.h>

typedef struct s_node
{
	int	value;
}	t_node;

void	check_arguments(int argc, char **argv);
void	ft_error(void);
bool	init_stack(int argc, char **argv, t_list **stack_a);
void	free_node(void *content);
void	print_stack(t_list *stack);

void	swap(t_list **stack);
void	sa(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

#endif
