#include "differ.h"

Node * CreateNode()
{
	Node * new_one = (Node *)calloc(1, sizeof(Node));

	new_one->sign 		= NULL;
	new_one->temp 		= NULL;
	new_one->value 		= 0;
	new_one->function	= NULL;

	new_one->left 		= NULL;
	new_one->right 		= NULL;

	return new_one;
}

Node * CreateSignNode(char * arg, Node * left_node)
{
	Node * node = CreateNode();

	node->sign 	= arg;
	node->left 	= left_node;

	return node;
}

Node * CreateNumNode(int arg_value)
{
	Node * node = CreateNode();

	node->value = arg_value;

	return node;
}

void ShowTree(Node * node)
{
	if(node->value)
		printf("value = %d\n", node->value);
	else if(node->temp)
		printf("temp = %s\n", node->temp);
	else if(node->temp)
		printf("sign = %s\n", node->sign);
	else if(node->function)
		printf("function = %s\n", node->function);

	printf("\n");

	if(node->left)
		ShowTree(node->left);

	if(node->right)
		ShowTree(node->right);
}
