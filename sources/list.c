/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:51:48 by allefran          #+#    #+#             */
/*   Updated: 2025/02/17 13:12:25 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->bin_value = ft_binary_convert(value);
	node->next = NULL;
	return (node);
}

void	ft_add_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	ft_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ft_print_node(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}
