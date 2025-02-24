/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:55:22 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/24 20:17:46 by emorillo         ###   ########.fr       */
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
		printf("%d -> ", node->value);
		node = node->next;
	}
	//free(node);
}

void init(char **str, int count)
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
//	printf("\nA\n");
//	printlst(stack_a);//imprime la lista A, antes de ordenar
	//printf("\n\nB\n");
	//printlst(stack_b);
	//sa(&stack_a);
	//printlst(stack_a);//imprime la lista A, modificada
	//pa(&stack_a, &stack_b);
	//printf("\n\nB\n");
	//printlst(stack_b);
	//printf("\n\nA\n");
	//printlst(stack_a);
	//printf("\n\nA\n");
//	pb(&stack_b, &stack_a);
//	printf("\nB\n");
	//printlst(stack_b);
	//printf("\nA\n");
	//printlst(stack_a);
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
printf("\nA\n");
printlst(stack_a);  // Lista A original
printf("\nB\n");
printlst(stack_b);  // Lista B vacía inicialmente

// Mueve el primer elemento de A a B
pb(&stack_b, &stack_a);
printf("\nB después de pb\n");
printlst(stack_b);  // Lista B debería tener el primer elemento de A

// Realiza la rotación de A
ra(&stack_a);
printf("\nA después de ra\n");
printlst(stack_a);  // Lista A debería estar rotada

// B nuevamente
printf("\nB después de pb y ra\n");
printlst(stack_b);

printf("\nAA\n");
rev_rotate(&stack_a);
printlst(stack_a);


}


