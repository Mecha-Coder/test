#ifndef MINISHELL_H
#define MINISHELL_H

//*******************************
// LIBARIES
//*******************************

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

//*******************************
// CONSTANT
//*******************************

#define FALSE 0
#define TRUE 1

#define PROMPT "\001\e[0m\e[33m\002Minishell> \001\e[0m\002"

//*******************************
// STRUCT
//*******************************

typedef struct s_env
{
    char *key;
    char *val;
    struct s_env *next;
} t_env;

/*
IN  Mode       File            fd
0    <      | infile
1    <<     | delimited
2           |             | pipe[0]
OUT 
3    >      | outfile     |
4    >>     | outfile     |
5           |             | pipe[1]
*/

typedef struct s_file
{
    int mode;
    char file[100];
    int fd;
    struct s_file *next;
} t_file

typedef struct s_tree
{
    char **cmd;
    char **out;
}

typedef struct s_shell
{
    int exit_code; // 1
    int interactive_mode;
    char *input;
    t_env *env;

} t_shell;

//*******************************
// PROTOTYPE
//*******************************

int is_blank(char *s);

#endif