#include "shell.h" 
/**
 * main - function for simple shell main
 * @ac: arguments ++
 * @av: Arguments 
 * return: o (success)
*/

int main(int ac, char **argv)
{
    char *thread = NULL, **instruct = NULL;
    int position = 0;
    (void) ac;
    (void) argv;

    while (1)
    {
        thread = temoraeez_read_line();
        if (thread == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (position);
        }

        free(thread);
        instruct = tr_tokenizer(thread);
        if (!instruct)
        continue;

        



        position = tr_execute(instruct, argv);
    }
}
