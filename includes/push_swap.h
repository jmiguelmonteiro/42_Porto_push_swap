/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:23:52 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/24 11:50:53 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdbool.h>

typedef struct s_content
{
	int	value;
}	t_content;

void	check_arguments(int argc, char **argv);
void	ft_error(void);

bool	init_stack(int argc, char **argv, t_list **stack_a);
void	free_node(void *content);
void	free_stack(t_list **stack);
void	print_stack(t_list *stack);

bool		push(t_list **stack, t_content *content);
t_content	*pop(t_list **stack);

void	swap(t_list **stack);
void	sa(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

#endif
