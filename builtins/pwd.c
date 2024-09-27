/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:36:36 by jetan             #+#    #+#             */
/*   Updated: 2024/09/27 20:05:06 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtins_pwd()
{
	char	buf[1024];
	
	if (getcwd(buf, sizeof(buf)) != NULL)
		printf("%s\n", buf);
	else
		perror("pwd");
}
// int main()
// {
// 	builtins_pwd();
// }