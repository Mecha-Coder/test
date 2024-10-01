/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/10/01 16:57:47 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

builtin_cd(char **av)
{
	char	*oldpwd;
	char	*home;
	
	oldpwd = getenv("PWD");
	home = getenv("HOME");
	if (!av[1])//no argument
	{
		if(chdir(home))
		{
			
		}
	}
	else if (path == '-')//back to previous dir + print out pwd
	{
		
	}
	else if (path == '..' || path == '/')// "cd /""
	{
		if (path == '/')
	}
	else if (path == '~')
	{
		
	}
	else
	{
		printf("%s: No such file or directory", path);
	}
}

int	main(int ac, char **av)
{
	(void) ac;
	builtin_cd(av);
}