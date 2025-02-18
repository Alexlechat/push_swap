/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:53:49 by allefran          #+#    #+#             */
/*   Updated: 2025/02/17 13:59:28 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_size(*stack_a);
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

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
	if (ft_check_null(argc, argv) || ft_check_incorrect_value(argc, argv)
		|| ft_check_duplicate(argc, argv) || ft_check_integer(argc, argv))
		return (1);
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_node = ft_init_node(value);
		ft_add_node(&stack_a, new_node);
		i++;
	}
	ft_sort_small_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
