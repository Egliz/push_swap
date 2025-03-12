/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:55:22 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/12 19:29:53 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}

t_stack	*lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*new(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

void	printlst(t_stack *node)
{
	if (node == NULL)
	{
		printf("\nlista vacia.\n");
		return ;
	}
	//printf("esta en lists.c\n");
	while (node != NULL)
	{
		printf("%d[%d] -> ", node->value, node->index);
		//printf("\n[%d]\n\n", node->index);
		node = node->next;
	}
	free_stack(&node);
}
/*
	printf("\nA\n");
	printlst(stack_a);//imprime la lista A, antes de ordenar
	printf("\n\nB\n");
	printlst(stack_b);
	sa(&stack_a);
	printf("\nA\n");
	printlst(stack_a);//imprime la lista A, modificada
	pb(&stack_b, &stack_a);
	printf("\n\nB\n");
	printlst(stack_b);
	pa(&stack_a, &stack_b);
	printf("\nA\n");
	printlst(stack_a);
	ra(&stack_a);
	printf("\n\nA\n");
	printlst(stack_a);
	rb(&stack_b);
	printf("\n\nB\n");
	printlst(stack_b);
	rra(&stack_a);
	printf("\nA\n");
	printlst(stack_a);
	rrb(&stack_b);
	printf("\nB\n");
	printlst(stack_b);
	//ra(&stack_a);
	//printf("\nlista A despues del ra\n");
	//printlst(stack_a);
	//printlst(stack_b);//imprime la lista B, modificada
	//rb(&stack_b);
	//printf("\nB\n");
	//printlst(stack_b);
	//printf("\nA\n");
	//printlst(stack_a);
	//free(stack_a); tambien podria ser free(nb); ya que termine de usarlo, despues de aqui no vuelvo a utilizar ese array

	// Imprime antes de cualquier operación
//printf("\nA\n");
//printlst(stack_a);  // Lista A original
//printf("\nB\n");
//printlst(stack_b);  // Lista B vacía inicialmente

// Mueve el primer elemento de A a B
//pb(&stack_b, &stack_a);
//printf("\nB después de pb\n");
//printlst(stack_b);  // Lista B debería tener el primer elemento de A

// Realiza la rotación de A
//printf("\n\n");
//ra(&stack_a);
//printf("\nA después de ra\n");
//printlst(stack_a);  // Lista A debería estar rotada

// B nuevamente
//printf("\nB después de pb y ra\n");
//printlst(stack_b);

printf("\nDespues de rra\n");
rra(&stack_a);
printf("\n\n");
printlst(stack_a);
printf("\nB\n");
printlst(stack_b);
*/



