/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/10/09 18:53:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



builtin_cd(char **av)
{
	char cwd[1024];
	char	*oldpwd;
	char	*home;
	
	oldpwd = getenv("PWD");
	home = getenv("HOME");
	arg_count(av, "cd");
	if (!av[1])//no argument
	{
		//back to root
	}
	else if (ft_strcmp(av[1], '-') == 0)
	{
		
	}
	else
	{
		
	}
}

int	main(int ac, char **av)
{
	(void) ac;
	builtin_cd(av);
}