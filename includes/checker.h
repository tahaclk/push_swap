/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:29 by tcelik            #+#    #+#             */
/*   Updated: 2023/03/10 15:35:29 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);
int			is_sorted(t_stack *stack);
int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rb(t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		rev_rotate(t_stack **stack);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **src, t_stack **dest);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		swap(t_stack *stack);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_sb(t_stack **stack_b);
void		do_sa(t_stack **stack_a);
int			is_sorted(t_stack *stack);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
char		*word_create(char	*s, char c);
int			word_counter(char const *s, char c);
char		*get_next_line(int fd);
char		*line_creater(char *str_buf);
char		*line_reader(int fd, char *str_buf);
int			ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_new_str_buf(char *str_buf);
int			ft_strcmp(const char *s1, const char *s2);

#endif
