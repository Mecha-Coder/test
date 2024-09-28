/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:03 by jetan             #+#    #+#             */
/*   Updated: 2024/09/28 20:34:23 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_numeric(char *str)
{
	int	i;
	
	i = -1;
	if (str[0] == '-')
		i = 1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

void	builtins_exit(char **av)
{
	int	exit_status;
	
	if (av[1])
	{
		if (is_numeric())
	}
}