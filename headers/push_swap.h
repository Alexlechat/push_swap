/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:11 by allefran          #+#    #+#             */
/*   Updated: 2025/02/18 12:39:06 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/headers/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	char			*bin_value;
	struct s_stack	*next;
}	t_stack;

//atol.c
long	ft_atol(const char *nptr);

//binary.c
char	*ft_binary_convert(int number);

//check_sorted.c
int		ft_is_sorted(t_stack *stack);

//list.c
t_stack	*ft_init_node(int value);
void	ft_add_node(t_stack **stack, t_stack *new_node);
int		ft_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_print_node(t_stack *stack);

//max.c
int		ft_get_max(t_stack *head);
int		ft_get_max_size(int max);

//move.c
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);

//normalize.c
void	ft_normalize(t_stack **stack_a);

//parsing.c
int		ft_check_null(int argc, char **argv);
int		ft_check_incorrect_value(int argc, char **argv);
int		ft_check_duplicate(int argc, char **argv);
int		ft_check_integer(int argc, char **argv);

//radix.c
void	ft_radix(t_stack **stack_a, t_stack **stack_b);

//sort_3.c
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

#endif
