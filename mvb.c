/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:11:56 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/23 22:04:15 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//pa, pb
//ra, rb

void pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	if(*b == NULL)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	if (*a == NULL)
	{
		(*a) = tmp;
		(*a)->next = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	tmp->next = *a;
	(*a) = tmp;
	write(1, "pa\n", 3);
}

void pb(t_stack **b, t_stack **a)
{
	t_stack *tmp;

	if(*a == NULL)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	if(*b == NULL)
	{
		(*b) = tmp;
		(*b)->next = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	tmp->next = *b;
	(*b) = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_stack **a)
{
	t_stack *tmp;
	t_stack	*last;
	
	if(*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a);//guarda la referencia al primer nodo (como quien dice tmp ahora es el primero (la cabeza))
	(*a)= (*a)->next;//moviendo la cabeza al segundo nodo, para que sea el primero
	last = (*a); // ahora es una referencia al segundo
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);

}

