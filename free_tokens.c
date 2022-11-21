#include "main.h"

/**
 * free_tokens - free & nullify an array of strings
 * @tokens: pointer to an array of tokens
 */

void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
		return;

	tok = *tokens;
	if (!tok)
		return;

	while (*tok)
		free(*tok++);
	free(*tokens);

	*tokens = NULL;
}