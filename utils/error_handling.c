/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:02:40 by jetan             #+#    #+#             */
/*   Updated: 2024/10/09 15:30:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_message(char *builtin, char *arg, char *mssg)
{
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(mssg, 2);
	ft_putstr_fd("\n", 2);
}

int	arg_count(char **args)
{
	int	count;
	
	count = 0;
	while (args[count])
		count++;
	return (count);
}
