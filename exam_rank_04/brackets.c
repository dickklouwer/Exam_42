/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 08:32:46 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/26 08:49:50 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	while (str[i])
		i++;
	return (i);
}

int isMatchingPair(char open, char close)
{
	if (open == '{' && close == '}')
		return (1);
	else if (open == '(' && close == ')')
		return (1);
	else if (open == '[' && close == ']')
		return (1);
	return (0);
}

int BalancedPharentesis(char *str)
{
	int i = 0;
	int top = -1;
	char	*stack;
	int		str_len;

	str_len = ft_strlen(str);
	stack = (char *)malloc((str_len + 1) * sizeof(char));
	if (!stack)
		return (0);
	stack[str_len + 1] = '\0';
	while (str[i])
	{
		if (str[i] == '['  || str[i] == '{' || str[i] == '(')
		{
			top++;
			stack[top] = str[i];
		}
		else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			if (top == -1)
			{
				free(stack);
				return (0);
			}
			if (isMatchingPair(stack[top], str[i]))
				top--;
			else
			{
				free(stack);
				return (0);
			}
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
	if (BalancedPharentesis(argv[1]))
		printf("Balanced!\n");
	else
		printf("Not Balanced!\n");
}