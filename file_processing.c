#include "differ.h"

long long FSize(FILE * ptrfile)
{
	if(!ptrfile)
		return EMPTY_FILE_ERR;

	long long curroff = ftell(ptrfile);

	fseek(ptrfile, 0, SEEK_END);

	long long size = ftell(ptrfile);

	fseek(ptrfile, curroff, SEEK_SET);

	return size;
}

char * MakeArray(FILE * fileptr)
{
	long long size = FSize(fileptr);

	char * first_arr = (char *)calloc(size + 1, sizeof(char));
	char * second_arr = (char *)calloc(size + 1, sizeof(char));

	fread(first_arr, sizeof(char), size + 1, fileptr);

	for(int i = 0; i < size; i++)
		second_arr[i] = '\0';

	for(int i = 0, j = 0; i < size; i++, j++)
	{
		if(first_arr[i] == '\n')
			break;

		if(first_arr[i] != ' ')
			second_arr[j] = first_arr[i];
		else
			j--;
	}

	return second_arr;
}