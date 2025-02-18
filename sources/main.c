/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:53:49 by allefran          #+#    #+#             */
/*   Updated: 2025/02/18 12:52:15 by allefran         ###   ########.fr       */
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

static void	ft_initialize_stack(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		value;
	t_stack	*new_node;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_node = ft_init_node(value);
		if (!new_node)
		{
			ft_free_stack(stack_a);
			return ;
		}
		ft_add_node(stack_a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (ft_check_null(argc, argv) || ft_check_incorrect_value(argc, argv)
		|| ft_check_duplicate(argc, argv) || ft_check_integer(argc, argv))
		return (1);
	ft_initialize_stack(argc, argv, &stack_a);
	if (ft_is_sorted(stack_a) == 1)
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	ft_sort_small_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
