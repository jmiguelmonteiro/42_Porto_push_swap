/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:19:35 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/23 17:25:24 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check_arg_is_int(char *nptr)
{
	long	value;
	int		signal;

	value = 0;
	signal = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
		if (*nptr < '0' || *nptr > '9')
			ft_error();
	}
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			value = value * 10 + *nptr++ - '0';
		else
			ft_error();
		if (((value * signal) > INT_MAX) || ((value * signal) < INT_MIN))
			ft_error();
	}
}

static void check_arg_is_duplicate(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) )
				ft_error();
			j++;
		}
		i++;
	}	
}

void	check_arguments(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < (argc - 1))
	{
		check_arg_is_int(argv[i + 1]);
		i++;
	}
	check_arg_is_duplicate(argc, argv);
}
