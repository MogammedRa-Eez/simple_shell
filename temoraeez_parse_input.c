#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
 * temoraeez_parse_input - Tokenizes the input command line.
 * @line: The command line to be tokenized.
 *
 * Return: Array of tokens.
 */
char **temoraeez_parse_input(char *line)
{
   int bufsize = 64, position = 0;
   char **tokens = malloc(bufsize * sizeof(char *));
   char *token;

   if (!tokens)
   {
       perror("Allocation error");
       exit(EXIT_FAILURE);
   }

   token = strtok(line, " \t\r\n\a");
   while (token != NULL)
   {
       tokens[position] = token;
       position++;

       if (position >= bufsize)
       {
           bufsize += 64;
           tokens = realloc(tokens, bufsize * sizeof(char *));
           if (!tokens)
           {
               perror("Allocation error");
               exit(EXIT_FAILURE);
           }
       }
       token = strtok(NULL, " \t\r\n\a");
   }
   tokens[position] = NULL;
   return tokens;
}


