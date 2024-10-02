/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:03:34 by jetan             #+#    #+#             */
/*   Updated: 2024/10/02 18:23:08 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* check validate variable name */
int	valid_name(char *name)
{
	int	i;
	
	if (ft_strncmp("0123456789", name[0], 10) == 0)
		return (0);
	i = 0;
	while (name[++i])
	{
		if (name[i] < 101 && name[i] > 172 && name[i] < 60 && name[i] > 71)
			return (0);
	}
	return (1);
}

void	builtin_export(char *arg)
{
	int	i;
	
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
	{
		if (!valid_name(arg[i]))
			printf("%s: not a valid identifier", arg);
		else
	}
	else
	{
		if (!valid_name(arg[i]))
			printf("%s: not a valid identifier", arg);
	}
}

int main(int ac, char **av)
{
	(void)ac;
	builtin_export(*av);
}
