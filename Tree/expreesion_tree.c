#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

//Struct Binary Tree
typedef struct Node tree;
struct Node
{
    char info;
    tree *child_1, *child_2, *parent;
};
tree *p=NULL, *temp;

//Struct Stack
typedef struct 
{
    tree *leaves[max];
    int indeks;
}stack;
stack opr, opn;

//fungsi stack
void inisialisasi_stack (stack *);
int isFull (stack *);
int isEmpty (stack *);
void push (stack *);
tree *pop (stack *);
tree *allocation(char);

//fungsi tranversal
void prefix(tree *);
void infix(tree *);
void postfix(tree *);

//variabel global
int i;
char data[max];

int main() 
{
    puts("<===============>EXPRESSION TREE<===============>");
    inisialisasi_stack(&opr);
    inisialisasi_stack(&opn);
    printf("Arithmatic Expression : ");
    fflush(stdin);
    gets(data);
    for (i=0; data[i] != '\0'; i++)
	{
        if (data[i]!=')' && data[i]!=' ')
		{
			p = allocation(data[i]);
            if((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <= 'z'))
                push(&opn);
            else
                push(&opr);
        }
        else if (data[i]==')')
		{
            p = pop(&opr);
            p->child_2 = pop(&opn);
            p->child_2->parent = p;
            p->child_1 = pop(&opn);
            p->child_1->parent = p;
            push(&opn);
            pop(&opr);
        }
    }
    p = pop(&opr);
    p->child_2 = pop(&opn);
    p->child_2->parent = p;
    p->child_1 = pop(&opn);
    p->child_1->parent = p;
    puts("\nNotasi Prefix:");
    prefix(p);
    puts("\n\nNotasi Infix:");
    infix(p);
    puts("\n\nNotasi Postfix:");
    postfix(p);
    return 0;
}

void inisialisasi_stack (stack *s)
{
    s->indeks = 0;
}

int isFull (stack *s)
{
    if(s->indeks == max)
        return 1;
    else
        return 0;
}

int isEmpty (stack *s)
{
    if(s->indeks == 0)
        return 1;
    else
        return 0;
}

void push(stack *s)
{
    if (isFull(s))
        puts("Stack Overflow");
    else
	{
		s->leaves[s->indeks] = p;
        ++(s->indeks);
    }
}

tree *pop (stack *s)
{
    if (isEmpty(s)) 
	{
        puts("Stack Underflow");
        return 0;
    }
    else 
	{
		--(s->indeks);
        temp = s->leaves[s->indeks];
    }
    return temp;
}

tree *allocation(char c)
{
	tree *p;
    p = (tree *)malloc(sizeof(tree));
    if(p == NULL)
	{
        puts("\nFailed to Allocation, Memory Error!\n");
        exit(0);
    }
    p->child_1 = NULL;
    p->child_2 = NULL;
    p->parent = NULL;
    p->info = c;
    return p;
}

void prefix(tree *root)
{
	if(root!=NULL)
	{
		printf("%c",root->info);
		prefix(root->child_1);
		prefix(root->child_2);
	}else
		return;
}

void infix(tree *root)
{
	if(root!=NULL)
	{
		infix(root->child_1);
		printf("%c",root->info);
		infix(root->child_2);
	}else
		return;
}

void postfix(tree *root)
{
	if(root!=NULL)
	{
		postfix(root->child_1);
		postfix(root->child_2);
		printf("%c",root->info);
	}else
		return;
}
