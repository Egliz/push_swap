/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:11:56 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/24 19:32:15 by emorillo         ###   ########.fr       */
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

void	rotate(t_stack **node)
{
	t_stack *tmp;
	t_stack	*last;
	
	if(*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node);//guarda la referencia al primer nodo (como quien dice tmp ahora es el primero (la cabeza))
	(*node)= (*node)->next;//moviendo la cabeza al segundo nodo, para que sea el primero
	last = (*node); // ahora es una referencia al segundo
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	if(*a == NULL)
		return ;
	rotate(a);
	if(write(1, "ra\n", 3) == 0)
	{
		free(a);
		wrerror();
	}
}

void rb(t_stack **b)
{
	if(*b == NULL)
		return ;
	rotate(b);
	if(write(1, "rb\n", 3) == 0)
	{
		free(b);
		wrerror();
	}
}
