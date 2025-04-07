/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:54 by emorillo          #+#    #+#             */
/*   Updated: 2025/04/07 20:19:50 by emorillo         ###   ########.fr       */
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

void	print_stacks(t_stack **a, t_stack **b)
{
	printlst(*a);
	printf("\n\n");
	printlst(*b);
	printf("\n\n");

}

void sort_bigg(t_stack **a, t_stack **b)
{
	printf("\nA\n");
	printf("\n\n");
	printlst(*a);
	printf("\n\n");
	while((size(*a)) > 3 && (size(*b)) < 2)
		pb(b, a);
	assign_index(a);
	assign_index(b);
	printf("\nB\n");
	printlst(*b);
	printf("\nA\n");
	printlst(*a);
	printf("\n\n");
	while((size(*a)) > 3)
	{
		ft_rotation(a, b);
		assign_index(a);
		assign_index(b);
		printf("\nA\n");
		printlst(*a);
		printf("\nB\n");
		printlst(*b);
		pb(b, a);
		assign_index(a);
		assign_index(b);
	}
	if(size(*a)== 3)
		sort_three(a);
	printf("\n\n");
	printf("\nA\n");
	printlst(*a);
	printf("\nB\n");
	printlst(*b);
	printf("\n\n");	
	//rotate_b(b);
	assign_index(a);
	assign_index(b);
	printf("\n\n");
	printf("\nA\n");
	printlst(*a);
	printf("\nB\n");
	printlst(*b);
	printf("\n\n");
}

void sort_stack(t_stack **a, t_stack **b)
{
	while((size(*a)) > 3)
	{
		assign_index(a);
		sort_bigg(a, b);
	}
	if(size(*a) == 2)
	{
		assign_index(a);
		sort_two(a);
	}
	else if(size(*a) == 3)
	{
		assign_index(a);
		sort_three(a);
	}
	printf("\nalgo\n");//borrar despues que vea que las funciones anteriores funcionan

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
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
	free(nb);
	free_stack(stack_a);
	//free_stack(stack_b);
}

void rotate_b (t_stack **b)
{
	t_stack *tmp;

	tmp = *b;

	while(tmp->value > tmp->next->value || tmp->next->value == max_value(*b))
		{
			rb(b);
			tmp = *b;
			if (tmp->value == max_value(*b))
				return ;
		}
	
}
