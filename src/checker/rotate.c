/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:30 by tcelik            #+#    #+#             */
/*   Updated: 2023/03/10 15:34:31 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (get_stack_size(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tail = get_stack_bottom(*stack);
		tmp->next = NULL;
		tail->next = tmp;
	}
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
