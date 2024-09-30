/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:03 by jetan             #+#    #+#             */
/*   Updated: 2024/09/30 16:40:09 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_numeric(char *str)
{
	int	i;
	
	i = -1;
	if ((str[0] == '-' || str[0] == '+') && (str[1] != '-' && str[1] != '+'))
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
		if (is_numeric(av[1]))
		{
			exit_status = ft_atoi(av[1]);
			printf("exit\n");
			exit(exit_status);
		}
		else
		{
			printf("exit: %s: numeric argument required\n", av[1]);
			exit(1);
		}
	}
	else
	{
		printf("exit\n");
		exit(0);
	}
}
//haven't handle the too many argument ex: exit 4 2
int main(int ac, char **av)
{
	(void)ac;
	builtins_exit(av);
}