/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:10:15 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/13 19:32:33 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
//	t_stack	**a;
	int count;

//	a = NULL;
	count = argc - 1;
	if(argc >= 2)
		verification(argv, count);
	init(argv, count);
	//sa(a);
//	printlst(*a);
	return (0);
}
