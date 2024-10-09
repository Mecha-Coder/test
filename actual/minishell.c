#include "minishell.h"

/* Initialize
- Initialize t_shell struct
- Evaluate if shell run on
    # Interactive mode: ac=1 
    # None-interative : ac=2 && !is_blank(av[1])
- Setup local environment variable which is a copy of the 
**env and stored in a linked-list 
*/
int initialize(t_shell *data, int ac, char **av, char **env)
{
    *data = (t_shell){0, TRUE, NULL};
    if (ac > 2)
        return (FALSE);
    if (ac == 2 && !is_blank(av[1]))  //.minishell "dnsaknl;ndsak"
        data->interactive_mode = FALSE;
    if (!create_env_list(data, env)) // Initialize env
        return (FALSE);
    return (TRUE);
}

void interactive(t_shell *data)
{
    while (1)
    {
        data->input = readline(PROMPT);
        add_to_history(data->input);
        if (build_tree(data))
            data->exit_code = run_tree(data);
    }
}



/* main
- Do initialization & check flow of program whether to run as 
interactive (prompt for input) or none-interactive (directly execute command passed as arg)
*/
int main(int ac, char **av, char **env)
{
    t_shell data;

    if (!initialize(&data, ac, av, env)) {;}
        // Handle input error
    if (data.interactive_mode)
        interactive(&data);
    else
        none_interactive(&data); 
}