/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   html_validator.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 09:08:31 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/26 10:27:19 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char ft_strlen_delim(char *str, char delim)
{
	int i = 0;

	while (str[i] != delim)
	{
		i++;
	}
	return (i);
}

char	*opentag(char *str)
{
	int i = 0;
	char *temp;
	
	int strlen = ft_strlen_delim(str, '>');
	if (!(temp = malloc(strlen * sizeof(char))))
		return (NULL);
	return (strncpy(temp, str, strlen));
}

char	*closingtag(char *str)
{
	int i = 0;
	char *temp;
	
	int strlen = ft_strlen_delim(str, '>');
	if (!(temp = malloc(strlen * sizeof(char))))
		return (NULL);
	return (strncpy(temp, str, strlen));
}

int	selfclosingtag(char *str)
{
	if (str[0] == 'i' && str[1] == 'm' && str[2] == 'g')
		return (1);
	return (0);
}

int html_validator(char *str)
{
	int i = 0;
	int top = -1;
	char **stack;
	
	if (!(stack = (char **)malloc(1054 * sizeof(char *))))
		return (0);
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] != '/')
		{
			if (selfclosingtag(&str[i + 1]))
			{
				while (str[i] != '>')
					i++;
				continue ;
			}
			top++;
			stack[top] = opentag(&str[i]);
			while (str[i] != '>')
				i++;
		}
		else if (str[i] == '<' && str[i + 1] == '/')
		{
			if (top == -1)
			{
				free(stack);
				return (0);
			}
			else
			{
				if (strncmp(&str[i + 2], stack[top], ft_strlen_delim(&str[i + 2], '>')))
				{
					free(stack[top]);
					top--;	
				}
				else
				{
					free(stack);
					return (0);
				}
			}
			while (str[i] != '>')
				i++;
		}
		i++;
	}
	if (top != -1)
	{
		free(stack);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (html_validator(argv[1]))
		printf("OK\n");
	else
		printf("KO\n");
}