/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:45 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/07 16:05:26 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/libft/libft.h"

//FUNCIONES
//FTS OF VERIFICATION
int verification(char **str, int cantidad);
int is_number(char **str);
int duplicate(int *nb, int cantidad);
int main(int argc, char **argv);
//

#endif
