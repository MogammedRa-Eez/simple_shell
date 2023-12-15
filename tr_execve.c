#include "shell.h"

/**
 * print_execution_error - print error execve
 * 
 * @vars: structure vars
 * @num: num of line
 */

void print_execution_error(vars_t *vars, int num)
{
	char *num_str;

	num_str = convert_integer_to_string(num);
	write(STDERR_FILENO, vars->program, calculate_string_length(vars->program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num_str, calculate_string_length(num_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, vars->array_tokens[0], calculate_string_length(vars->array_tokens[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	free(num_str);
}



/**
 * execute_command - system call command
 * 
 * @vars: string
 * @num: char for delimit
 * @env: enviroment
 * 
 * Return: 0 (success)
 */

int execute_command(vars_t *vars, int num, char **env)
{
	char *cmd;
	int status = 0;
	pid_t parentid;
	
	parentid = fork();
	if (parentid == 0)
	{
		if (access(vars->array_tokens[0], X_OK) == 0)
		{
			cmd = vars->array_tokens[0];
			if (execve(cmd, vars->array_tokens, env) == -1)
				perror(vars->program);
		}
		else
		{
			cmd = get_command_path(vars->array_tokens[0], env);
			if (cmd != NULL)
			{
				if (execve(cmd, vars->array_tokens, env) == -1)
					perror(vars->program);
				free(cmd);
			}
			else
			{
				errno = 127;
				print_execution_error(vars, num);
			}
			free(vars->buffer);
		}
		free(vars->array_tokens);
		_exit(errno);
	}
	wait(&status);
	free(vars->array_tokens);
	errno = status % 255;
	return (errno);
}

