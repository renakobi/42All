/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:58:00 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/13 17:46:11 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct stack
{
	int				content;
	struct stack	*next;
	int				index;
}					t_stack;

void	r_rotate_a(t_stack **a, char c);
void	push_a(t_stack **a, t_stack **b, char c);
void	swap_a(t_stack **a, char c);
void	rotate_a(t_stack **a, char c);
void	swap_both(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	r_rotate_both(t_stack **a, t_stack **b);
void	append_node(t_stack **stack, t_stack *new);
int		stack_size(t_stack *a);
void	push_to_b(t_stack **a, t_stack **b);
void	count_2(t_stack **a);
void	init(t_stack *a, t_stack **first, t_stack **second,
			t_stack **third);
void	count_3(t_stack **a);
void	five_andfour(t_stack **a, t_stack **b);
int		find_lowest(t_stack *a);
int		*stack_to_array(t_stack *a, int size);
void	ft_sort_int_tab(int *tab, int size);
void	indexing(int *r, t_stack *a, int size);
void	sort_stack(t_stack *a, int size);
int		find_max_index(t_stack *b);
int		find_index_position(t_stack *b, int index);
void	push_back_to_a(t_stack **a, t_stack **b);
int		chunk_in_stack(t_stack *a, int start, int end);
void	move_chunk_to_b(t_stack **a, t_stack **b, int start, int end);
void	rotate_top_and_push(t_stack **a, t_stack **b, int top);
void	reverse_and_push(t_stack **a, t_stack **b, int bottom);
void	chunk_sort(t_stack **a, t_stack **b, int size);
void	chunk_params(int size, int *count, int *chunk_size);
int		get_closest_top(t_stack *a, int start, int end);
int		get_closest_bottom(t_stack *a, int start, int end);
void	free_stack(t_stack **stack);
void	free_both(t_stack **a, t_stack **b);
t_stack	*new_node(int value);
int		is_valid_number(const char *str);
long	ft_atol(const char *str);
int		fill_stack(t_stack **a, int ac, char **av);
int		fill_stack(t_stack **a, int ac, char **av);
int		has_duplicates(t_stack *a);
int		is_sorted(t_stack *a);
int		check_and_init(t_stack **a, int argc, char **argv);
char	**ft_split(const char *s, char c);
int		prepare_stack(t_stack **a, int argc, char **argv);
size_t	ft_strlen(const char *str);
int		word_count(const char *str, char c);
char	*fill_word(const char *str, int start, int end);
void	ft_initiate_vars(size_t *i, int *j, int *s_word);
void	free_all(char **args, t_stack **a);
void	free_split(char **arr);
#endif