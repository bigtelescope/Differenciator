#include "differ.h"

int main()
{
	FILE * fileptr = fopen("example.txt", "r");

	char * sample = MakeArray(fileptr);

	int result = GetG(sample);
	printf("result is %d\n", result);

	return 0;
}

long long FSize(FILE * ptrfile)
{
	if(ptrfile == NULL)
	{
		perror("Error of file reading");
		return -1;
	}

	long long curroff = ftell(ptrfile);
	fseek(ptrfile, 0, SEEK_END);
	long long size = ftell(ptrfile);
	fseek(ptrfile, curroff, SEEK_SET);

	return size;
}

char * MakeArray(FILE * fileptr)
{
	long long size = FSize(fileptr);

	char * arr = (char *)calloc(size + 1, sizeof(char));

	fread(arr, sizeof(char), size, fileptr);

	return arr;
}

int GetN(char ** sample)
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

int GetG(char * sample)
{
	char * pointer = sample;

	int value = GetE(&pointer);

	assert(*pointer == '\0');

	return value;
}

int GetE(char ** sample)
{
	int value = GetN(sample);

	char symbol;

	while(**sample == '+' || **sample == '-')
	{
		symbol = **sample;

		(*sample)++;

		int temp = GetN(sample);

		if(symbol == '+')
			value += temp;
		else
			value -= temp;
	}

	return value;
}