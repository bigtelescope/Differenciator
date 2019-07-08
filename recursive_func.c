#include "differ.h"

Tree * GetResult(char * sample)
{
	char * pointer = sample;

	Tree * tree = (Tree *)calloc(ONE, sizeof(Tree));

	tree->node = GetAdd(&pointer);

	if(*pointer != '\0')
		printf("bad pointer is %c\n", *pointer);

	return tree;
}

Node * GetAdd(char ** sample)
{
	//printf("HERER'S GetAdd\n");
	Node * left_node = GetNum(sample);

	char 	symbol;
	Node * 	new_one;

	if(**sample == '+' || **sample == '-')
	{
		symbol = **sample;

		(*sample)++;

		if(symbol == '+')
			new_one = CreateSignNode("+", left_node);
		else
			new_one = CreateSignNode("-", left_node);

		new_one->right = GetAdd(sample);

		return new_one;
	}

	return left_node;
}

Node * GetMult(char ** sample)
{
	return NULL;
}

Node * GetNum(char ** sample)
{
	int temp = 0;

	assert(**sample != '\0');

	while('0' <= **sample && **sample <= '9')
	{
		temp = temp * 10 + (**sample - '0');
		(*sample)++;
	}

	//printf("temp = %d\n", temp);

	return CreateNumNode(temp);
}