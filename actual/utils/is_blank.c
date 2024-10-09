#include "../minishell.h"

int is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' 
		|| c == '\v' || c == '\f' || c == '\r');
}

int is_blank(char *s)
{
	while(s && *s)
	{
		if (!is_space(*s++))
			return (FALSE);
	}
	return (TRUE);
}

/*
int main()
{
	printf("%d\n", is_blank("\t  0  \n"));
	return 0;
}
*/