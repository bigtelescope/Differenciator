#ifndef DIFFER_H
#define DIFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define ONE 1
#define TWO 2
#define X_DIFFERENTIAL ONE

typedef struct Node
{
	char 		sign;
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

long long FSize	(FILE * fptr);
char * MakeArray(FILE * fptr);

void 	ShowTree 	(Node *);

Node * CreateNode		();
Node * CreateVolNode	();
Node * CreateNumNode	(int);
Node * CreateLnNode 	(Node *);
Node * CreateSignNode	(char, Node *);

Tree * GetResult	(char *);
Node * GetAdd		(char **);
Node * GetMult 		(char **);
Node * GetBracket 	(char **);
Node * GetDegree 	(char **);
Node * GetLn 		(char **);

Node * GetNum 		(char **);
Node * GetVariable	(char **);

Node * d(Node *);

Node * DiffTempNode		();
Node * DiffAddNode		(Node *);
Node * DiffDivNode		(Node *);
Node * DiffMultNode		(Node *);
Node * DiffLnNode 		(Node *);
Node * DiffDegreeNode 	(Node *);

Node * 	Bypass 	(Node *);
bool 	isEmpty (Node *);
bool 	isUnit 	(Node *);
bool 	areSame	(Node *, Node *);

#endif