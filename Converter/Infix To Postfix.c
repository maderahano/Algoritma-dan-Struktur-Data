#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 20
#define MAX 20

typedef char itemType;
typedef struct{
    itemType data[MAXSTACK];
    int index;
} stack;

stack oprd;

itemType pop(stack *s);
itemType topStack(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
int priority(itemType x);
void push(itemType x, stack *s);
void initStack(stack *s);
void inInfix();
void toPostfix();


int main()
{
	char str[MAX];
    
	inInfix(str);
	toPostfix(str);

    return 0;
}

int isFull(stack *s)
{
    if(s->index == MAXSTACK)
        return 1;
    else
        return 0;
}

int isEmpty(stack *s)
{
    if(s->index == 0)
        return 1;
    else
        return 0;
}

void initStack(stack *s)
{
    s->index = 0;
}

void push(itemType x, stack *s)
{
    if(isFull(s))
        puts("Stack Overflow");
    else
	{
        s->data[s->index] = x;
        ++(s->index);
    }
}

itemType pop(stack *s)
{
    itemType temp;
    if(isEmpty(s))
	{
        puts("Stack Underflow");
        exit(0);
    }else
	{
        --(s->index);
        temp = s->data[s->index];
    }
    return temp;
}

itemType topStack(stack *s)
{
    return s->data[s->index-1];
}

int priority(itemType x)
{
    if(x == '(')
        return 1;
    else if(x == '+' || x == '-')
        return 2;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '^')
        return 4;
    else
        return 0;
}

void inInfix(char *str)
{
	printf("Input Equation of Infix: ");
    fflush(stdin);
    gets(str);
}

void toPostfix(char *str)
{
    int i, j;
    char x, *pstr;

    initStack(&oprd);

    printf("Equation of Postfix: ");
    for(i = 0; i < strlen(str); i++)
	{
        if(isalnum(str[i]))
            printf("%c", str[i]);
        else if(str[i] == '(')
            push(str[i], &oprd);
        else if(str[i] == ')')
            while((x = pop(&oprd)) != '(')
                printf("%c", x);
        else
		{
            if(isEmpty(&oprd))
                push(str[i], &oprd);
            else
			{
                while(priority(str[i]) <= priority(topStack(&oprd)))
                    printf("%c", pop(&oprd));
                push(str[i], &oprd);
            }
        }
    }
    while(!isEmpty(&oprd))
        printf("%c", pop(&oprd));
}




