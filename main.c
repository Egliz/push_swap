/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:10:15 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/10 13:50:33 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//FTS OF VERIFICATION
int	is_number(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if(str[i][j] == '-' || str[i][j] == '+')
			j++;
		while(str[i][j])
		{
			if(!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int ordered(int *nb, int cantidad)
{
	int i;
	int j;

	i = 1;
	j = i-1;
	while (i < cantidad)
	{
		if(nb[i] > nb[j])
		{
			j++;
		}
		else
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int *conv(char **str, int cantidad)
{
	int i;
	int j;
	int *nb;

	i = 0;
	j = 1;
	nb = (int *)malloc(cantidad * sizeof(int));
	if (nb == NULL)
		return (0);
	while (i < cantidad)
	{
		nb[i] = ft_atoi(str[j]);
		i++;
		j++;
	}
	return (nb);
}

int duplicate(int *nb, int cantidad)
{
	int i;
	int j;

	i = 0;
	while(i < cantidad)
	{
		j = i + 1;
		while(j < cantidad)
		{
			if(nb[i] == nb[j])
			{
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int verification (char **str, int cantidad)
{
	//int i;
	int *nb;
	//int j;
	
	//j = 1;
	//i = 0;
	if(!is_number(str))
	{
		write(2, "ErrorNoNum\n", 11);
		exit(1);
	}
	nb = conv(str, cantidad);
	//nb = (int *)malloc(cantidad * sizeof(int));
	//if (nb == NULL)
	//	return(0);
	//while (i < cantidad)
//	{
//		nb[i] = ft_atoi(str[j]);
//		j++;
//		i++;
//	}
	if(duplicate(nb, cantidad) == 0)
	{
		free(nb);
		write(2, "ErrorDup\n", 9);
		exit (1);
	}
	if(ordered(nb, cantidad) == 0)
	{
		free(nb);
		write(2, "Ordenados. QUITAR ESTE WRITE\n",29);
		exit (1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int cantidad;

	cantidad = argc - 1;
	if(argc >= 2)
		verification(argv, cantidad); // argv[1], argv[2]
	return (0);
}
