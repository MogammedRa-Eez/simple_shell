#include "shell.h"

char **tr_tokenizer(char *thread)
{
    char *tr_token = NULL;
    char *tr_tmp = NULL;
    char **instruct = NULL;
    int tr_cpt = 0;
    int tr = 0;

    if (!thread)
        return NULL;
    
    tr_tmp = tr_strdup(thread);

    tr_token = strtok(tr_tmp, DELIM);
    if (tr_token == NULL)
    {
        free(tr_tmp);
        return NULL;
    }

    while (tr_token)
    {
        tr_cpt++;
        tr_token = strtok(NULL, DELIM);
    }
    free(tr_tmp);

    instruct = malloc(sizeof(char *) * (tr_cpt + 1));
    if (!instruct)
    {
        return NULL;
    }

    tr_tmp = tr_strdup(thread);

    tr_token = strtok(tr_tmp, DELIM);
    while (tr_token)
    {
        instruct[tr] = tr_token;
        tr_token = strtok(NULL, DELIM);
        tr++;
    }
    free(tr_tmp);

    instruct[tr] = NULL;
    return instruct;
}

