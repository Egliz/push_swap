/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:10:15 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/06 18:43:31 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "push_swap.h"
//#include "libft.h"
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

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

int	ft_atoi(char *nptr)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
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
//	i++;
	return (1);
}
int verification (char **str, int cantidad)
{
	int i;
	int *nb;
	int j;
	
	j = 1;
	i = 0;
	if(!is_number(str))
	{
		write(1, "ErrorNoNum\n", 11);
		return (0);
	}
	nb = (int *)malloc(cantidad * sizeof(int));
	if (nb == NULL)
		return(0);
	while (i < cantidad)
	{
		nb[i] = ft_atoi(str[j]);
		j++;
		i++;
	}
	if(duplicate(nb, cantidad) == 0)
	{
		free(nb);
		write(1, "ErrorDup\n", 9);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
//	int i;
	int cantidad;

	cantidad = argc - 1;
//	i = 1;
//	while(i < argc)
		verification(argv, cantidad); // argv[1], argv[2]
	return (0);
}
