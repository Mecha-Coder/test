/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:03 by jetan             #+#    #+#             */
/*   Updated: 2024/10/03 16:54:32 by jetan            ###   ########.fr       */
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

// void	builtin_exit(char **av)
// {
// 	int	exit_status;
	
// 	if (av[1])
// 	{
// 		if (is_numeric(av[1]))
// 		{
// 			exit_status = ft_atoi(av[1]);
// 			printf("exit\n");
// 			exit(exit_status);
// 		}
// 		else
// 		{
// 			printf("exit: %s: numeric argument required\n", av[1]);
// 			exit(1);
// 		}
// 	}
// 	else
// 	{
// 		printf("exit\n");
// 		exit(0);
// 	}
// }

void	builtin_exit(char **av)
{
	int	exit_status;
	
	exit_status = 0;
	if (av[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit(exit_status);
	}
	if (!is_numeric(av[1]))
	{
		// error_message();
		write(2, "exit: a: numeric argument required\n", 32);
		exit(2);
	}
	if (av[1] && av[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return;
	}
	exit_status = ft_atoi(av[1]);
	ft_putstr_fd("exit\n", 2);
	exit (exit_status);
	
}
//haven't handle error message
int main(int ac, char **av)
{
	(void)ac;
	builtin_exit(av);
}