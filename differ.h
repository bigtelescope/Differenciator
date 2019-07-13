#ifndef DIFFER_H
#define DIFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define ONE 			1
#define TWO 			2
#define MINUS_ONE 		-1
#define X_DIFFERENTIAL	ONE

#define DECIMAL			10

#define EMPTY_FILE_ERR 	-1

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

Node * CreateNode			();
Node * CreateVolNode		();
Node * CreateNumNode		(int);
Node * CreateLnNode 		(Node *);
Node * CreateSignNode		(char, Node *);

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

Node * 	Bypass 		(Node *);
bool 	isEmpty 	(Node *);
bool 	isUnit 		(Node *);
bool 	areSame		(Node *, Node *);
bool 	areEqual	(Node *, Node *);
bool 	areValue	(Node *, Node *);
bool 	areTemp 	(Node *, Node *);

Node * AddOptimization 	(Node *);
Node * DivOptimization 	(Node *);
Node * SubOptimization 	(Node *);
Node * MultOptimization	(Node *);

Node * Optimisation_1	(Node *);
Node * Optimisation_2	(Node *);
Node * Optimisation_3	(Node *);
Node * Optimisation_4	(Node *);
Node * Optimisation_5	(Node *);
Node * Optimisation_6	(Node *);
Node * Optimisation_7	(Node *);
Node * Optimisation_8	(Node *);
Node * Optimisation_9	(Node *);
Node * Optimisation_10	(Node *);
Node * Optimisation_11	(Node *);
Node * Optimisation_12	(Node *);
Node * Optimisation_13	(Node *);
Node * Optimisation_14	(Node *);
Node * Optimisation_15	(Node *);

void 	WriteTree		(Node *, FILE *);
void 	WriteFunction	(Node *, FILE *);
void 	LeftBrackets 	(Node *, FILE *);
void 	RightBrackets 	(Node *, FILE *);
void 	EndBrackets 	(Node *, FILE *);
void 	MakeTex			(Node *, Node *);

#endif