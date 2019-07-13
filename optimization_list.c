#include "differ.h"

Node * AddOptimization(Node * node)
{
	if(!isEmpty(node->left) && isEmpty(node->right))
		return node = node->left;

	if(isEmpty(node->left) && !isEmpty(node->right))
		return node = node->right;

	if(isEmpty(node->left) && isEmpty(node->right))
		return node = CreateNode();

	if(areTemp(node->left, node->right))
		return Optimisation_8(node);

	if(areValue(node->left, node->right))
		return node = CreateNumNode(node->left->value + node->right->value);

	return NULL;
}

Node * DivOptimization(Node * node)
{

	if(isEmpty(node->left))
		return node = CreateNode();

	if(isUnit(node->right))
		return node = node->right;

	return NULL;
}

Node * SubOptimization(Node * node)
{
	if(areValue(node->left, node->right))
		return node = CreateNumNode(node->left->value - node->right->value);

	if(areSame(node->left, node->right))
		return node = CreateNode();

	if(!isEmpty(node->left) && isEmpty(node->right))
		return node = node->left;

	if(isEmpty(node->left) && !isEmpty(node->right))
		return node = Optimisation_7(node);

	return NULL;
}

Node * MultOptimization(Node * node)
{
	if(isEmpty(node->left) || isEmpty(node->right))
		return node = CreateNode();

	if(isUnit(node->left))
		return node = node->right;
	else if(isUnit(node->right))
		return node = node->left;

	if(areValue(node->left, node->right))
		return CreateNumNode(node->left->value * node->right->value);

	if(node->left->sign == '*')
	{
		if(areValue(node->right, node->left->left))
			return Optimisation_1(node);
		if(areValue(node->right, node->left->right))
			return Optimisation_2(node);		
	}

	if(node->right->sign == '*')
	{
		if(areValue(node->right->left, node->left))
			return Optimisation_3(node);

		if(areValue(node->right->right, node->left))
			return Optimisation_4(node);
	}

	if(node->left->sign == '/')
		if(areValue(node->right, node->left->left))
			return Optimisation_5(node);

	if(node->right->sign == '/')
		if(areValue(node->left, node->right->left))
			return Optimisation_6(node);

	if(node->left->sign == '^')
	{
		if(areTemp(node->left->left, node->right))
			return Optimisation_9(node);

		if(node->right->sign == '/' &&
			areTemp(node->left->left, node->right->right))
			return Optimisation_10(node);

		if(node->right->sign == '*' &&
			areTemp(node->left->left, node->right->left))
			return Optimisation_11(node);

		if(node->right->sign == '^' &&
			areTemp(node->left->left, node->right->left))
			return Optimisation_12(node);
	}

	if(node->right->sign == '^')
	{
		if(areTemp(node->left, node->right->left))
			return Optimisation_13(node);

		if(node->left->sign == '/' &&
			areTemp(node->left->right, node->right->left))
			return Optimisation_14(node);

		if(node->left->sign == '*' &&
			areTemp(node->left->left, node->right->left))
			return Optimisation_15(node);
	}

	return NULL;
}

Node * Optimisation_1(Node * node)
{
	Node * left_arg = CreateNode();
	left_arg->value = node->left->left->value * node->right->value;

	node->right = node->left->right;
	node->left 	= left_arg;

	return node;
}

Node * Optimisation_2(Node * node)
{
	Node * left_arg = CreateNode();
	left_arg->value = node->left->right->value * node->right->value;

	node->right = node->left->left;
	node->left 	= left_arg;

	return node;
}

Node * Optimisation_3(Node * node)
{
	Node * left_arg = CreateNode();
	left_arg->value  = node->right->left->value * node->left->value;

	node->left 	= left_arg;
	node->right	= node->right->right;

	return node;
}

Node * Optimisation_4(Node * node)
{
	Node * left_arg = CreateNode();
	left_arg->value  = node->right->right->value * node->left->value;

	node->left 	= left_arg;
	node->right	= node->right->left;

	return node;
}

Node * Optimisation_5(Node * node)
{
	Node * left_arg = CreateNode();
	left_arg->value = node->right->value * node->left->left->value;

	node->sign 	= '/';
	node->right = node->left->right;
	node->left 	= left_arg;

	return node;
}

Node * Optimisation_6(Node * node)
{
	Node * left_arg = CreateNode();
	left_arg->value = node->left->value * node->right->left->value;

	node->sign 	= '/';
	node->right = node->right->right;
	node->left 	= left_arg;

	return node;
}

Node * Optimisation_7(Node * node)
{
	node->sign = '*';
	node->left = CreateNumNode(MINUS_ONE);

	return node;
}

Node * Optimisation_8(Node * node)
{
	node->value = '*';
	node->left 	= CreateNumNode(TWO);

	return node;
}

Node * Optimisation_9(Node * node)
{
	Node * right_node = CreateSignNode('+', node->left->right);
	right_node->right = CreateNumNode(ONE);

	node->sign 	= '^';
	node->left 	= CreateVolNode();
	node->right = right_node;

	return node;
}

Node * Optimisation_10(Node * node)
{
	Node * right_node = CreateSignNode('-', node->left->right);
	right_node->right = CreateNumNode(ONE);

	node->right = node->right->left;
	node->left->right = right_node;

	return node;
}

Node * Optimisation_11(Node * node)
{
	Node * right_node = CreateSignNode('+', node->left->right);
	right_node->right = CreateNumNode(ONE);

	node->right = node->right->right;
	node->left->right = right_node;

	return node;
}

Node * Optimisation_12(Node * node)
{
	Node * right_node = CreateSignNode('+', node->left->right);
	right_node->right = node->right->right;

	node->sign 	= '^';
	node->left 	= CreateVolNode();
	node->right = right_node;

	return node;
}

Node * Optimisation_13(Node * node)
{
	Node * right_node = CreateSignNode('+', node->right->right);
	right_node->right = CreateNumNode(ONE);

	node->sign 	= '^';
	node->left 	= CreateVolNode();
	node->right = right_node;

	return node;
}

Node * Optimisation_14(Node * node)
{
	Node * right_node = CreateSignNode('-', node->right->right);
	right_node->right = CreateNumNode(ONE);

	node->left = node->left->left;
	node->right->right = right_node;

	return node;
}

Node * Optimisation_15(Node * node)
{
	Node * right_node = CreateSignNode('+', node->right->right);
	right_node->right = CreateNumNode(ONE);

	node->left = node->left->right;
	node->right->right = right_node;

	return node;
}

