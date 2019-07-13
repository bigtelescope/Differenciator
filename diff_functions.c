#include "differ.h"

Node * d(Node * node)
{
	if(node->value)
		return CreateNode();

	if(node->temp)
		return DiffTempNode();

	if(node->sign == '+' || node->sign == '-')
		return DiffAddNode(node);

	if(node->sign == '*')
		return DiffMultNode(node);

	if(node->sign == '/')
		return DiffDivNode(node);

	if(node->sign == '^')
		return DiffDegreeNode(node);

	if(node->function)
		if(!strcmp("ln", node->function))
			return DiffLnNode(node);

	if(node->value == 0)//default situation
		return CreateNode();
}

Node * DiffAddNode(Node * node)
{
	Node * differ_node = CreateNode();

	differ_node->sign 	= node->sign;
	differ_node->left 	= d(node->left);
	differ_node->right 	= d(node->right);

	return differ_node;
}

Node * DiffTempNode()
{
	Node * temp_node = CreateNode();
	temp_node->value = X_DIFFERENTIAL;

	return temp_node;
}

Node * DiffMultNode(Node * node)
{
	Node * new_left  = d(node->left);
	Node * new_right = d(node->right);
	
	Node * left_node = CreateSignNode('*', new_left);
	left_node->right = node->right;

	Node * right_node = CreateSignNode('*', node->left);
	right_node->right = new_right;

	Node * main_node = CreateSignNode('+', left_node);
	main_node->right = right_node;

	return main_node;
}

Node * DiffDivNode(Node * node)
{
	Node * new_left  = d(node->left);
	Node * new_right = d(node->right);

	Node * left_node = CreateSignNode('*', new_left);
	left_node->right = node->right;

	Node * right_node = CreateSignNode('*', node->left);
	right_node->right = new_right;

	Node * numerator = CreateSignNode('-', left_node);
	numerator->right = right_node;

	Node * denominator = CreateSignNode('*', node->right);
	denominator->right = node->right;

	Node * main_node = CreateSignNode('/', numerator);
	main_node->right = denominator;

	return main_node;
}

Node * DiffLnNode(Node * node)
{
	Node * one_num = CreateNode();
	one_num->value = ONE;

	Node * temp_node = CreateSignNode('/', one_num);
	temp_node->right = node->right;

	Node * main_node = CreateSignNode('*', temp_node);
	main_node->right = d(node->right);

	return main_node;
}

Node * DiffDegreeNode(Node * node)
{
	Node * static_node = CreateSignNode('^', node->left);
	static_node->right = node->right;

	Node * argument_node = CreateSignNode('*', node->right);
	argument_node->right = CreateLnNode(node->left);

	Node * main_node = CreateSignNode('*', static_node);
	main_node->right = d(argument_node);

	return main_node;
}