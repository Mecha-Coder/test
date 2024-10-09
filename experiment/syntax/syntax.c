#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR 0
#define PIPE 1    // |
#define OR 2      // ||
#define AND 3     // &&
#define OBRK 4    // (
#define CBRK 5    // )
#define SQT 6     // '
#define DQT 7     // "
#define APPD 8    // >>
#define WR 9      // >
#define HERE 10   // <<
#define RD 11     // <

#define TRUE 1
#define FALSE 0

typedef struct s_label
{
    int type;
    int index;
} label;

int is_str(char c)
{
    return(c != '(' 
        && c != ')' 
        && c != '\'' 
        && c != '\"' 
        && c != ' '
        && c != '\t'  
        && c != '|'
        && c != '<'
        && c != '>'
        );
}

void analyze_syntax(char *s)
{
    int i, j;
    int state;
    int skip;
    int count_SQT;
    int count_DQT;
    int count_bracket;
    label list[100];
    
    i = 0;
    j = 0;
    count_SQT = 0;
    count_DQT = 0;
    count_bracket = 0;
    skip = FALSE;
    while(s[i])
    {
        if (skip || is_str(s[i]))
        {
            while(skip || is_str(s[i])) { i++; state = STR; }
            list[j++]
        }
        else {
            if (s[i] == '\"')           { state = DQT;   count_DQT++;      skip = !skip; }
            else if (s[i] == '\'')      { state = SQT;   count_SQT++;      skip = !skip;  }
            else if (s[i] == '(')       { state = OBRK;  count_bracket++;  skip = count_bracket; }
            else if (s[i] == ')')       { state = CBRK;  count_bracket--;  skip = count_bracket; }  //Error: bracket goes negative 
            else if (s[i] == '|')
            {
                if (s[i + 1] == '|')  { s + 1; state = OR; }
                else                  { state = PIPE; }                          
            }
            
            else if (s[i] == '&')
            {
                if (s[i + 1] == '&') {s + 1, state = AND; }
                // else error
            }
            
            else if (s[i] == '>')
            {
                if (s[i + 1] == '>') {s + 1, state = APPD; }
                else                 {state = WR;}
            }

            else if (*s == '<')
            {
                if (s[i + 1] == '<') {s + 1, state = HERE; }
                else                 {state = RD;}
            }
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1] && av[1][0])
        analyze_syntax(av[1]);
    return 0;
}