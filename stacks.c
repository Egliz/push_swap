/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:54 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/06 16:04:55 by emorillo         ###   ########.fr       */
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
	//int len;
	
	printlst(*a);
	printf("\n\n");
	if(size(*a) > 3)
		pb(b, a);
	if(size(*a) > 3)
		pb(b, a);
	printlst(*b);
	printf("\n\n");
	num = (*a)->value;
	//len = size(*a);
	if(num > max_value(*b))
	{
		while((*b)->value != max_value(*b))
			rb(b);
		printf("\naqui si\n");
	}
	if(num < min_value(*b))
	{
		while((*b)->value != min_value(*b))
			rrb(b);
	}
	else
		correct_position(b, num);
//	if(size(*a) > 3)
	//pb(b, a);
//	if(size(*a)== 3)
//		sort_stack(a, b);
	printf("\nA\n");
	printlst(*a);
	printf("\nB\n");
	printlst(*b);
}

void sort_stack(t_stack **a, t_stack **b)
{
	int len;

	len = size(*a);

	//con el len dentro para que se actualice cada vez, posible while para que vaya entrando hasta que no sea nulo, y asi poder ordenar los numeros que queden en A si son 2 o 3
		if(len == 2)
			sort_two(a);// implemento sa, en sort_two
		else if(len == 3)
		{
			sort_three(a);//llo necesario para 3 nodos, en sort_three
			printf("\nsoy 3\n");
		}
		else if(len > 3)//va un else
		{
			while(size(*a) > 3)
				sort_bigg(a, b);//si hay mas de 3, hago pb en sort bigg
			printf("\nsoy bigg\n");
		}
		else
			printf("\nalgo\n");//borrar despues que vea que las funciones anteriores funcionan
//		(*a) = (*a)->next;
//	}
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
