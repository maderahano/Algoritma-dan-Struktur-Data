#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;
///disini saya menggunakan SLL
struct simpul
{
    int data;
    node *next;
};
node *p, *head, *tail, *ptail;

//fungsi program
void Continue();
void Undo();
void Reset();

//fungsi stack
void push(int);
void pop();

//variabel global
char opr;
int opn1, opn2, result=0;

int main()
{
	int choice;
    
	while(1)
	{
		do
	    {
	        puts("<===============>MENU<===============>");
	        puts("1. Continue");
	        puts("2. Undo");
	        puts("3. Reset");
	        puts("4. Exit");
	        printf("Input yout choice : ");
	        fflush(stdin);
	        scanf("%i", &choice);
	        
	        switch(choice)
	        {
	        case 1:
	            Continue();
	            break;
	        case 2:
	            Undo();
	            break;
	        case 3:
	            Reset();
	            break;
	        case 4:
	        	exit(0);
	        default:
	        	printf("Your choice input is not in our Menu\nPlease Try Again\n");
	        }
	    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
	}
}

void Continue()
{
    if(head==NULL)
	{
        printf("Input Operand 1 : ");
        fflush(stdin);
		scanf("%d",&opn1);
        printf("Input the operator : ");
        fflush(stdin);
        opr = getchar();
		printf("Input Operand 2 : ");
        fflush(stdin);
		scanf("%d",&opn2);
		switch (opr)
		{
            case '+':
                result = opn1 + opn2;
                break;
            case '-':
                result = opn1 - opn2;
                break;
            case '*':
                result = opn1 * opn2;
                break;
            case '/':
                result = opn1 / opn2;
                break;
            case '%':
                result = opn1 % opn2;
                break;
        }
        push(result);
        printf("Result : %d\n", result);
    }
    else
	{
        opn1=head->data;
        printf("Operand 1 : %d\n", opn1);
        fflush(stdin);

        printf("Input the operator : ");
        fflush(stdin);
        opr = getchar();
		printf("Operand 2 : ");
        fflush(stdin);
		scanf("%d",&opn2);
        fflush(stdin);
        switch (opr)
		{
            case '+':
                result = opn1 + opn2;
                break;
            case '-':
                result = opn1 - opn2;
                break;
            case '*':
                result = opn1 * opn2;
                break;
            case '/':
                result = opn1 / opn2;
                break;
            case '%':
                result = opn1 % opn2;
                break;
        }
        push(result);
        printf("Result : %d\n", result);
    }
}

void Undo()
{
    tail=head;
    if (head==NULL){
        puts("No history!");
    }
    else{
        pop();
    }
}

void Reset()
{
    free(head);
    head=NULL;
}

void push(int o)
{
    p=(node *)malloc(sizeof(node));
    p->data=o;
    p->next=NULL;

    if(head==NULL)
        head=p;
    else
        p->next=head;
    head=p;
}

void pop()
{
    p=(node *)malloc(sizeof(node));

    tail=head;
    ptail=head;
    if(tail==NULL){
        puts("No History");
    } else if(tail->next!=NULL){
        tail=tail->next;
        head=tail;
        free(ptail);
        ptail=NULL;
        printf("Operand 1 : %d\n", tail->data);
    } else{
        Reset();
        puts("Empty");
    }
}
