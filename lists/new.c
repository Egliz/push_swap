/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:11:11 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/12 17:34:19 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
/*
int	main()
{
	char	*num;
	t_list	*node;

	num = malloc(sizeof(char));
	if(num == NULL)
		return (1);
	num = "42";
	node = ft_lstnew(num);
	if(!node)
	{
	//	free(num);
		return (1);
	}
	printf("%s\n",(char *)node->content);
//	free(node->content);
	free(node);
	return (0);
}*/
