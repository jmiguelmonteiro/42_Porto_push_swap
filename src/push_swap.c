/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:54:10 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/21 18:44:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_arguments(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		while (i < argc)
		{
			args[i] = ft_strdup(argv[i + 1]);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	(void) stack_a;
	(void) stack_b;
	
	if (argc < 2)
		return (0);

	check_arguments(argc, argv);
	
	exit (0);
}
