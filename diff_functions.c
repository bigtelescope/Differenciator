#include "differ.h"


int GetNum(char ** sample)
{
	int temp = 0;

	assert(**sample != '\0');
	
	while('0' <= **sample && **sample <= '9')
	{
		temp = temp * 10 + (**sample - '0');
		(*sample)++;
	}

	return temp;
}

int GetResult(char * sample)
{
	char * pointer = sample;

	int value = GetAdd(&pointer);

	assert(*pointer == '\0');

	return value;
}

int GetAdd(char ** sample)
{
	int value = GetMult(sample);

	char symbol;

	while(**sample == '+' || **sample == '-')
	{
		symbol = **sample;

		(*sample)++;

		int temp = GetMult(sample);

		if(symbol == '+')
			value += temp;
		else
			value -= temp;
	}

	return value;
}

int GetMult (char ** sample)
{
	int value = GetBracket(sample);

	char operation;

	while(**sample == '*' || **sample == '/')
	{
		operation = **sample;

		(*sample)++;

		if(operation == '*')
			value = value * GetNum(sample);
		else
			value = value / GetNum(sample);
	}

	return value;
}

int GetBracket(char ** sample)
{
	if(**sample == '(')
	{
		(*sample)++;

		int value = GetAdd(sample);

		assert(**sample == ')');
		
		(*sample)++;

		return value;
	}
	else
		return GetNum(sample);
}