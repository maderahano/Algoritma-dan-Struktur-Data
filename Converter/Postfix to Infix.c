#include <stdio.h>
#include <string.h>

#define MAX 125

char stack[MAX][MAX];
int top = -1;

void pop(char *p);
void push(char *p);
void inPostfix(char *str);
void toInfix(char *str);

int main() 
{
	char str[MAX];
	
    inPostfix(str);
	toInfix(str);

    return 0;
}


void push(char *p) 
{
    if (top >= MAX -1) 
	{
            printf("Stack Overflow\n");
    }else 
	{
            top++;
            strcpy(stack[top], p);
    }
    return;
}

void pop(char *p) 
{
    if (top == -1) 
	{
            printf("Stack Underflow\n");
            return;
    }else 
	{
            strcpy(p, stack[top]);
            top--;
    }
    return;
}

void inPostfix(char *str)
{
	printf("Input Equation of Postfix: ");
    gets(str);
}

void toInfix(char *str){
    char a[MAX], b[MAX];
    int i, j, n = 0;

    for (i = 0; str[i] != '\0'; i++) 
	{
            if (str[i] == ' ')
                    continue;

            if (!isalnum(str[i])) 
			{
                    pop(a);
                    pop(b);
                    n = strlen(b);
                    b[n++] = str[i];
                    b[n] = '\0';
                    strcat(b, a);
                    push(b);
            }else 
			{
                    a[0] = str[i];
                    a[1] = '\0';
                    push(a);
            }
    }
    printf("Equation of Infix: ");
    for (i = 0; i <= top; i++) 
	{
            printf("%s",stack[i]);
    }
}


