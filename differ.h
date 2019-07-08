#ifndef DIFFER_H
#define DIFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ONE 1

typedef struct Node
{
	char *		sign;
	char * 		temp;
	int 		value;
	char * 		function;

	struct Node * 	left;
	struct Node * 	right;
}Node;

typedef struct Tree
{
	Node * node;
}Tree;

Node * 	CreateNode	();
void 	ShowTree 	(Node *);

Node * CreateNumNode	(int);
Node * CreateSignNode	(char *, Node *);

long long FSize	(FILE * fptr);
char * MakeArray(FILE * fptr);

Tree * GetResult	(char *);
Node * GetAdd		(char **);
Node * GetNum 		(char **);
Node * GetMult 		(char **);
Node * GetBracket 	(char **);

#endif