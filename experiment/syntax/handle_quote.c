#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NONE 0
#define SQ 1
#define DQ 2

int check_quote_count(const char *s)
{
	int i = 0;
	int state = NONE;
	int count_SQ = 0;
	int count_DQ = 0;
	int i_SQ = -1;
	int i_DQ = -1; 

	while(s[i])
	{
		if      (s[i] == '\"' && state == NONE) {state = DQ; count_DQ++; i_DQ = i;}
		else if (s[i] == '\'' && state == NONE) {state = SQ; count_SQ++; i_SQ = i;}
		else if (s[i] == '\"' && state == DQ)   {state = NONE; count_DQ++; i_DQ = i;} 
		else if (s[i] == '\'' && state == SQ)   {state = NONE; count_SQ++; i_SQ = i;}
		i++;
	}
	if (count_SQ % 2)
		return (i_SQ);
	if (count_DQ % 2)
		return (i_DQ);
	return (-1);
}

/*
int check_bracket(char *s)
{}

int check_operator(char *s)
{}
*/

void highlight_issue(int pos)
{
	int i;

	i = 0;
	while(i++ < pos)
		printf(" ");
	printf("↑\n");
}

void syntax_error_check(char *s)
{
	int status;

	status = check_quote_count(s);
	
	printf("\n%s\n", s);
	if (status > -1)
	{
		highlight_issue(status);
		printf("\nSyntax ERROR: Quote(s) not even amount\n");
	}
	else
		printf("\nSyntax OK\n");
	
		
	/*
	1) Single ' and double " quote count. Must be even
	2) Bracket ()
		- When looping bracket count can't go negative
		- When finish looping count must be zero.

	3) Only occur once or twice
		<< , < 
		>> , > 
		|| , |
	4) Must occur twice
		&& 

	// NOTE: Do not count or check when state is insde quote or bracket
	*/
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1] && av[1][0])
		syntax_error_check(av[1]);
	return 0;
}