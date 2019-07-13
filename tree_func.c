#include "differ.h"

Node * CreateNode()
{
	Node * new_one = (Node *)calloc(ONE, sizeof(Node));

	new_one->temp 		= NULL;
	new_one->sign 		= 0;
	new_one->value 		= 0;
	new_one->function	= NULL;

	new_one->left 		= NULL;
	new_one->right 		= NULL;

	return new_one;
}

Node * CreateSignNode(char arg, Node * left_node)
{
	Node * node = CreateNode();

	node->sign 	= arg;
	node->left 	= left_node;

	return node;
}

Node * CreateVolNode()
{
	Node * node = CreateNode();
	node->temp = "x";

	return node;
}

Node * CreateLnNode(Node * node)
{
	Node * main_node = CreateNode();

	main_node->function = "ln";
	main_node->right 	= node;

	return main_node;
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
	else if(node->sign)
		printf("sign = %c\n", node->sign);
	else if(node->function)
		printf("function = %s\n", node->function);
	else 
		printf("here is only value = 0\n");

	printf("\n");

	if(node->left)
		ShowTree(node->left);

	if(node->right)
		ShowTree(node->right);
}

bool isEmpty(Node * node)
{
	if(node->value || node->temp ||
	   			  node->function || node->sign)
		return false;
	else
		return true;
}

bool isUnit(Node * node)
{
	if(node->value == ONE)
		return true;
	else
		return false;
}

bool areSame(Node * left, Node * right)
{
	if(left->value == right->value && left->value)
		return true;
	else if(left->temp == right->temp && left->temp)
		return true;
	else
		return false;
}

bool areValue(Node * first, Node * second)
{
	if( (first->value	&& second->value)	||
		(first->value 	&& isEmpty(second)) ||
		(isEmpty(first) && second->value) 	||
		(isEmpty(first) && isEmpty(second)))
		return true;
	else
		return false;
}

bool areTemp(Node * first, Node * second)
{
	if(first->temp && second->temp)
		return true;
	else
		return false;
}

bool areEqual(Node * first, Node * second)
{
	if(areSame (first, second)			&&
		(first->left == second->left) 	&&
		(first->right == second->right))
		return true;
	else
		return false;
}

Node * Bypass(Node * node)
{
	Node * tempor;

	if(node->left)
		node->left = Bypass(node->left);

	if(node->right)
		node->right = Bypass(node->right);

	if(node->sign == '*')
		if(tempor = MultOptimization(node))
		{
			node = tempor;
			node = Bypass(node);
		}

	if(node->sign == '/')
		if(tempor = DivOptimization(node))
		{
			node = tempor;
			node = Bypass(node);
		}

	if(node->sign == '+')
		if(tempor = AddOptimization(node))
		{
			node = tempor;
			node = Bypass(node);
		}

	if(node->sign == '-')
		if(tempor = SubOptimization(node))
		{
			node = tempor;
			node = Bypass(node);
		}

	return node;
}
