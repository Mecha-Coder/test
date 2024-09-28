/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:17:06 by jetan             #+#    #+#             */
/*   Updated: 2024/09/28 14:17:09 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(char **av)
{
	int	i;
	int	new_line;
	
	i = 1;
	new_line = 1;
	if (av[1] != NULL && ft_strncmp(av[1], "-n", 2) == 0 && av[1][2] == '\0')
	{
		new_line = 0;
		i = 2;
	}
	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
}
// with % no newline
// without % newline
// int main()
// {
// 	char *args[] = {"echo", "-n", "hello", "world", NULL};
	
// 	builtin_echo(args);
// }