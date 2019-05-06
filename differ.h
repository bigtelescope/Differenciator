#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long FSize(FILE * fptr);
char * MakeArray(FILE * fptr);

int GetG(char * sample);
int GetN(char ** sample);
int GetE(char ** sample);