#include "differ.h"

Tree * GetResult(char * sample)
{
	char * pointer = sample;

	Tree * tree = (Tree *)calloc(ONE, sizeof(Tree));

	tree->node = GetAdd(&pointer);

	if(*pointer != '\0')
		printf("------bad pointer is %c-------\n", *pointer);

	return tree;
}

Node * GetAdd(char ** sample)
{
	Node * main_node = GetMult(sample);

	Node * temp_node;
	char symbol;

	while(**sample == '+' || **sample == '-')
	{
		symbol = **sample;

		(*sample)++;

		temp_node = main_node;

		if(symbol == '+')
			main_node = CreateSignNode('+', temp_node);
		else
			main_node = CreateSignNode('-', temp_node);

		main_node->right = GetMult(sample);
	}

	return main_node;
}

Node * GetMult(char ** sample)
{
	Node * main_node = GetDegree(sample);

	Node * temp_node;
	char symbol;

	while(**sample == '*' || **sample == '/')
	{
		symbol = **sample;

		(*sample)++;

		temp_node = main_node;

		if(symbol == '*')
			main_node = CreateSignNode('*', temp_node);
		else
			main_node = CreateSignNode('/', temp_node);

		main_node->right = GetDegree(sample);
	}

	return main_node;
}

Node * GetDegree(char ** sample)
{
	Node * main_node = GetLn(sample);

	if(**sample == '^')
	{
		Node * temp_node = main_node;

		(*sample)++;

		main_node = CreateSignNode('^', temp_node);
		main_node->right = GetLn(sample);
	}

	return main_node;
}

Node * GetLn(char ** sample)
{
	if(!strncmp(*sample, "ln", TWO))
	{
		(*sample) += TWO;
		return CreateLnNode(GetBracket(sample));
	}
	else
		return GetBracket(sample);
}

Node * GetBracket(char ** sample)
{
	if(**sample == '(')
	{
		(*sample)++;

		Node * brackets = GetAdd(sample);

		assert(**sample == ')');

		(*sample)++;

		return brackets;
	}
	else
		return GetNum(sample);
}

Node * GetNum(char ** sample)
{
	if('0' <= **sample && **sample <= '9')
	{
		assert(**sample != '\0');

		int temp = 0;

		while('0' <= **sample && **sample <= '9')
		{
			temp = temp * 10 + (**sample - '0');
			(*sample)++;
		}
		return CreateNumNode(temp);
	}
	else
		return GetVariable(sample);
}

Node * GetVariable(char ** sample)
{
	if(**sample == 'x')
	{	
		(*sample)++;
		return CreateVolNode();
	}
	else
		return NULL;
}
