/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/10/10 18:16:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_pwd()
{
	
}

void	cd_previous()
{
	char	*oldpwd;
	
	oldpwd = getenv("OLDPWD");
	if (chdir(oldpwd))
	{
		printf("%s", oldpwd);
	}
}

void	cd_home()
{
	char	*home;
	
	home = getenv("HOME");	
	if (!home)
	{
		error_msg("cd", "Home not set");
		return;
	}
	chdir(home);
}

void	builtin_cd(char **av)
{
	
	arg_count(av, "cd");
	if (!av[1])//no argument
		cd_home();
	else if (av[1] == '-')
		cd_previous();
	else if ()
}

int	main(int ac, char **av)
{
	(void) ac;
	// builtin_cd(av);
	// cd_previous();
	cd_home();
}