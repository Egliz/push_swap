/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:45 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/12 17:34:42 by emorillo         ###   ########.fr       */
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
//write
void	wrerror(void);
//main
int		main(int argc, char **argv);
//LISTAS
void	add_back(t_stack **lst, t_stack *new);
t_stack *new(int content);
t_stack	*lstlast(t_stack *lst);

#endif
