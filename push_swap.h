/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:45 by emorillo          #+#    #+#             */
/*   Updated: 2025/04/07 20:28:50 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "include/libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int			value;
	int			index;
	int			cheap;
	struct s_stack	*next;
}					t_stack;

//FUNCIONES
//FTS OF VERIFICATION
int		verification(char **str, int count);
int		is_number(char **str);
int		duplicate(long *nb, int count);
int		limit(long *nb, int count);
long	*conv(char **str, int count);
int		ordered(long *nb, int count);

//utils.c
void	free_stack(t_stack **stack);
int		find_max_position(t_stack *b);
int		find_min_position(t_stack *b);
//////
void	rotate_b(t_stack **b);
void	ft_rotation(t_stack **a, t_stack **b);
int		get_pos_of_b(t_stack **b, int node);
int		get_index_cheapest(t_stack **a, t_stack **b);
int		get_cost(int l, int index);
t_stack *ft_get_node(t_stack **stack, int index);

///////

int	max_value(t_stack **b);
int	min_value(t_stack *b);
//utils2.c
void	correct_position(t_stack **b, int num);
void	assign_index(t_stack **stack);
//int find_correct_position(t_stack *b, int num);

//void rotate_to_position(t_stack **b, int position, int len);

//write
void	wrerror(void);

//main.c
int		main(int argc, char **argv);

//LISTAS
//lists.c

void	add_back(t_stack **lst, t_stack *new);
t_stack *new(int content);
t_stack	*lstlast(t_stack *lst);
void	printlst(t_stack *node);

//lists1.c
int		size(t_stack *lst);

//stacks.c
void	init (char **str, int count, t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
void	sort_bigg(t_stack **a, t_stack **b);

//MOVEMENTS
void	move(t_stack **node);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **node);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **node);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
#endif
