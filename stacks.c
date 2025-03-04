/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:54 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/04 19:35:41 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//NO + FUNCIONES
void sort_two(t_stack **a)
{
	sa(a);
}

void sort_three(t_stack **a)//NO + LINEAS
{
	int pmro;
	int sdo;
	int tro;

	pmro = (*a)->value;
	sdo = (*a)->next->value;
	tro = (*a)->next->next->value;
	//las lineas son largas, poner el valor del 3ro en una variable
	if(pmro > sdo && pmro > tro && sdo > tro)
	{
		sa(a);
		rra(a);
	}
	else if(pmro > sdo && sdo < tro && pmro > tro)
		ra(a);
/*	else if()
	{	
		algo
		algo
	}
	else if
		algo
	else if
		algo
	*/
	else
		printf("No entreee");
	printlst(*a);
}
/*
void sort_bigg(t_stack **a, t_stack **b)
{

}
*/
void sort_stack(t_stack **a, t_stack **b)
{
	int len;

	len = size(*a);
	if(len == 2)
		sort_two(a);// implemento sa, en sort_two
	else if(len == 3)
		sort_three(a);//llo necesario para 3 nodos, en sort_three
	/*else
		sort_bigg(&a, &b);//si hay mas de 3, hago pb en sort bigg
	*/
	else
		printlst(*b);//borrar despues que vea que las funciones anteriores funcionan
}



void init(char **str, int count)//NO + LINEAS
{
	int		i;
	int		j;
	long	*nb;
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *node;

	i = 1;
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	nb = conv(str, count);
	while (i <= count)
	{
		node = new(nb[j]);
		add_back(&stack_a, node);
		j++;
		i++;
	}
	sort_stack(&stack_a, &stack_b);
}
