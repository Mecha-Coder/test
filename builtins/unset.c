/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:49 by jetan             #+#    #+#             */
/*   Updated: 2024/10/03 12:55:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unset(char **av)//haven't finish
{
	int	i;
	int	j;
	int	var_count = 0;//struct
	
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (j < var_count)
		{
		}
	}
}
