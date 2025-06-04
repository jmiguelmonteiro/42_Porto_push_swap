/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:17:34 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 12:17:34 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <libft.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_data
{
	int				value;
}	t_data;

void	check_arguments(int argc, char **argv);
void	ft_error(void);
bool	init_stack(int argc, char **argv, t_list **stack_a);
void	free_stack(t_list **stack);
void	print_stack(t_list *stack_a);
t_list	*ft_lstbeforelast(t_list *lst);

bool	is_stack_sorted(t_list *stack);
void	get_input(t_list **stack_a, t_list **stack_b);

bool	push(t_list **stack, t_data *content);
t_data	*pop(t_list **stack);
t_data	*peek(t_list *stack);
void	sa(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
