/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:53:23 by tcelik            #+#    #+#             */
/*   Updated: 2022/12/30 14:48:42 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	compare_m(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		do_sa(stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		do_sb(stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		do_ss(stack_a, stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		do_ra(stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		do_rb(stack_b);
	else if (ft_strcmp(input, "rr\n") == 0)
		do_rr(stack_a, stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		do_rra(stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		do_rrb(stack_b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		do_rrr(stack_a, stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		do_pa(stack_a, stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		do_pb(stack_a, stack_b);
	else
		write(1, "Error\n", 6);
}

void	main_check(int ac2, char **av2, t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	if (!is_correct_input(av2))
		exit_error(NULL, NULL);
	*stack_b = NULL;
	*stack_a = fill_stack_values(ac2, av2);
	assign_index(*stack_a, get_stack_size(*stack_a) + 1);
	str = get_next_line(0);
	while (str)
	{
		compare_m(str, stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char**av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**av2;
	int		ac2;

	if (ac < 2)
		return (0);
	ac2 = ac;
	av2 = av;
	if (ac == 2)
	{
		av2 = ft_split(av[1], ' ');
		av2[0] = word_create("./a.out", ' ');
		ac2 = word_counter(av[1], ' ');
	}
	main_check(ac2, av2, &stack_a, &stack_b);
	if (is_sorted(stack_a) && 0 == get_stack_size(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
