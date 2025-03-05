/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:54 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/05 21:05:59 by emorillo         ###   ########.fr       */
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
	int sdo;
	int tro;

	sdo = (*a)->next->value;
	tro = (*a)->next->next->value;
	//las lineas son largas, poner el valor del 3ro en una variable
	if((*a)->value > sdo && (*a)->value > tro && sdo > tro)
	{
		sa(a);
		rra(a);
	}
	else if((*a)->value > sdo && sdo < tro && (*a)->value > tro)
		ra(a);
	else if((*a)->value > tro && (*a)->value < sdo && sdo > tro)
		rra(a);
	else if((*a)->value < tro && (*a)->value > sdo && tro > sdo)
		sa(a);
	else if((*a)->value < sdo && (*a)->value < tro && sdo > tro)
	{
		rra(a);
		sa(a);
	}
	else
		return ;
	printlst(*a);
}

void sort_bigg(t_stack **a, t_stack **b)
{
	int num;
	
	printlst(*a);
	printf("\n\n");
	pb(b, a);
	pb(b, a);
	printlst(*b);
	printf("\n\n");
	num = (*a)->value;
	if(num > max_value(*b))
	{
		while((*b)->value != max_value(*b))
			rb(b);
	}
	else if(num < min_value(*b))
	{
		while((*b)->value != min_value(*b))
			rrb(b);
	}
	else
		llamar a correct_position(*b, num);
	printlst(*a);
	printf("\notra\n");
	printlst(*b);

}
void sort_stack(t_stack **a, t_stack **b)
{
	int len;

	len = size(*a);//con el len dentro para que se actualice cada vez, posible while para que vaya entrando hasta que no sea nulo, y asi poder ordenar los numeros que queden en A si son 2 o 3
	if(len == 2)
		sort_two(a);// implemento sa, en sort_two
	else if(len == 3)
		sort_three(a);//llo necesario para 3 nodos, en sort_three
	if(len > 3)
		sort_bigg(a, b);//si hay mas de 3, hago pb en sort bigg
	else
		printlst(*b);//borrar despues que vea que las funciones anteriores funcionan
}



void init(char **str, int count, t_stack **stack_a, t_stack **stack_b)//NO + LINEAS
{
	int		i;
	int		j;
	long	*nb;
	t_stack *node;

	i = 1;
	j = 0;
	nb = conv(str, count);
	while (i <= count)
	{
		node = new(nb[j]);
		add_back(stack_a, node);
		j++;
		i++;
	}
	sort_stack(stack_a, stack_b);
	free(nb);
	free_stack(stack_a);
	//free_stack(stack_b);
}
