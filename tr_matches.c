#include "shell.h"

/**
 * execute_builtin_env -  print out environ
 * 
 * @vars: string
 * @num: char for delimit
 * @env: environment
 * 
 * Return: token value (success)
 */

int execute_builtin_env(vars_t *vars, int num, char **env)
{
	int tr = 0;

	(void)vars;
	(void)num;

	while (env[tr])
	{
		write(STDOUT_FILENO, env[tr], calculate_string_length(env[tr]));
		write(STDOUT_FILENO, "\n", 1);
		tr++;
	}

	free(vars->array_tokens);

	return (1);
}

/**
 * execute_builtin_exit - print exit command
 * 
 * @vars: string
 * @num: char for delimit
 * @env: environment
 * 
 * Return: token value (success)
 */

int execute_builtin_exit(vars_t *vars, int num, char **env)
{
	char *num_str;
	(void)env;

	if (vars->array_tokens[1] != NULL)
	{
		errno = 0;
		errno = parse_string_to_int(vars->array_tokens[1]);
		if (errno == -1)
		{
			write(STDERR_FILENO, vars->program, calculate_string_length(vars->program));
			write(STDERR_FILENO, ": ", 2);
			num_str = convert_integer_to_string(num);
			write(STDERR_FILENO, num_str, calculate_string_length(num_str));
			write(STDERR_FILENO, ": exit: Illegal number: ", 24);
			write(STDERR_FILENO, vars->array_tokens[1], calculate_string_length(vars->array_tokens[1]));
			write(STDERR_FILENO, "\n", 1);
			free(num_str);
			free(vars->array_tokens);
			errno = 2;
			return (errno);
		}
	}
	free(vars->buffer);
	free(vars->array_tokens);
	if (errno > 255)
		errno %= 256;
	exit(errno);
}

/**
 * find_builtin_command - locate the command
 * 
 * @vars: structure vars
 * @num:  string
 * @env: environment
 * 
 * Return: token value (success)
 */

int find_builtin_command(vars_t *vars, int num, char **env)
{
	int tr;
	builtins_t check[] = {
		{"env", execute_builtin_env},
		{"exit", execute_builtin_exit},
		{NULL, NULL}};
	for (tr = 0; check[tr].name; tr++)
	{
		if (compare_strings(check[tr].name, vars->array_tokens[0]) == 0)
			return (check[tr].f(vars, num, env));
	}

	return (0);
}

