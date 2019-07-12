#include "differ.h"

void MakeTex(Node * primary, Node * secondary)
{
	FILE * tex_output = fopen("output.tex", "w");

	FILE * output_info = fopen("output_info.txt", "r");

	int info_size = FSize(output_info);
	char info[info_size];
	int nread;

	while(nread = fread(info, sizeof(char), sizeof(info), output_info))
    	fwrite(info, sizeof(char), nread, tex_output);

    fprintf(tex_output, "\\[");
    WriteTree(primary, tex_output);
    fprintf(tex_output, "\\]");

    fprintf(tex_output, "\n\\section{Output}\n\n");

    fprintf(tex_output, "\\[");
    WriteTree(secondary, tex_output);
    fprintf(tex_output, "\\]\n\\end{document}");
}

void WriteTree(Node * node, FILE * store)
{
	if(node->sign)
		LeftBrackets(node, store);

	if(node->left)
		WriteTree(node->left, store);

	if(node->sign)
		RightBrackets(node, store);

	if(node->function)
	{
		WriteFunction(node, store);
		return;
	}

	if(node->right)
		WriteTree(node->right, store);

	EndBrackets(node, store);

	if(node->value)
		fprintf(store, "%d ", node->value);

	if(node->temp)
		fprintf(store, "%s ", node->temp);
}

void WriteFunction(Node * node, FILE * store)
{
	if(!strcmp(node->function, "ln"))
	{
		fprintf(store, "ln(");
		WriteTree(node->right, store);
		fprintf(store, ") ");
	}
}

void LeftBrackets(Node * node, FILE * store)
{
	if(node->sign == '*' && node->left->sign == '+' ||
	   node->sign == '*' && node->left->sign == '-')
	{
		fprintf(store, "(");
	}

	if(node->sign == '/')
		fprintf(store, "\\frac{");
}

void RightBrackets(Node * node, FILE * store)
{
	if(node->sign == '*' && node->left->sign == '+' ||
	   node->sign == '*' && node->left->sign == '-')
	{
		fprintf(store, ")");
	}

	if(node->sign != '/')
		fprintf(store, "%c ", node->sign);

	if(node->sign == '*' && node->right->sign == '+' ||
	   node->sign == '*' && node->right->sign == '-')
	{
		fprintf(store, "(");
	}

	if(node->sign == '/')
		fprintf(store, "}{");
}

void EndBrackets(Node * node, FILE * store)
{
	if(node->sign == '*' && node->right->sign == '+' ||
	   node->sign == '*' && node->right->sign == '-')
	{
		fprintf(store, ")");
	}

	if(node->sign == '/')
		fprintf(store, "}");
}