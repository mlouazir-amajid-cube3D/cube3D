/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:27 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 17:12:32 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
#define CUB_3D

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
#include "../libft/libft.h"

void	print_error(char *mssg);
int		ft_strlen(char *s);
int		map_name(char *filename);
int map_name_check(char *filename);

#endif