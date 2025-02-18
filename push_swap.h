/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:45 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/18 17:53:21 by emorillo         ###   ########.fr       */
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

//utils.c
void	init (char **str, int count);

//MOVEMENTS
void	move(t_stack **node);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
#endif
