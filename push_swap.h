/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:45 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/10 17:38:32 by emorillo         ###   ########.fr       */
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
int verification(char **str, int count);
int is_number(char **str);
int duplicate(long *nb, int count);
int limit(long *nb, int count);
long *conv(char **str, int count);
int ordered(long *nb, int count);


void wrerror();



//MAIN
int main(int argc, char **argv);
//

#endif
