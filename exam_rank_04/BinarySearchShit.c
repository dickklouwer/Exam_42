#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int		value;
	struct	node* left;
	struct	node* right;
}				t_node;

t_node	*newNode(int data) {
	t_node* node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

int		totalNodes(t_node *node)
{
	static int root = 1;
	if (node == NULL)
		return (0);
	else
	{
		int lDepth = totalNodes(node->left);
		int rDepth = totalNodes(node->right);
		if (root == 1)
		{
			root = 0;
			return (lDepth + rDepth);
		}
		return (rDepth + lDepth + 1);
	}
}

int		SearchValue(t_node *node, int value)
{
	if (node == NULL)
		return (0);
	else
	{
		if (node->value == value)
			return (1);
			int lDepth = SearchValue(node->left, value);
			int rDepth = SearchValue(node->right, value);
			if (lDepth || rDepth)
				return (1);
			return (0):
	}
}

int main()
{
	t_node* root;

	root = newNode(1);
}