/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:53:49 by allefran          #+#    #+#             */
/*   Updated: 2025/02/13 08:50:43 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		value;
	t_stack	*new_node;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	if (ft_check_null(argc, argv) || ft_check_incorrect_value(argc, argv) || ft_check_duplicate(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_node = ft_init_node(value);
		ft_add_node(&stack_a, new_node);
		i++;
	}
	ft_printf("Stack before sorting :\n");
	ft_print_node(stack_a);
	ft_radix(&stack_a, &stack_b);
	ft_printf("Stack after sorting :\n");
	ft_print_node(stack_a);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
