/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:45 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/06 12:39:05 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "include/libft/libft.h"

typedef struct s_stack
{
	int			value;
	//int			index;
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
int		max_value(t_stack *b);
int		min_value(t_stack *b);

//utils2.c
void	correct_position(t_stack **b, int num);
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
