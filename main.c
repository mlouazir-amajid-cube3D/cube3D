/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:18 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 17:12:15 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2 || map_name_check(av[1]))
		return (print_error("Invalid Arguments"), 1);
	return 0;
}
