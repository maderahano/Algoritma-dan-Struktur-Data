#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 20

typedef char itemType;
typedef struct{
    itemType data[MAXSTACK];
    int index;
} stack;
int decimal, bil, i;
stack convertion;

int menu();
itemType pop(stack *s);
itemType intToChar(int x);
void initStack(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
void push(itemType x, stack *s);
void printoutStack(stack *s);
void inDecimal();
void toBiner();
void toOktal();
void toHeksa();

int main()
{
    int flag = 1;

    while(menu());

    return 0;
}

int menu()
{
    int choice;
	
	inDecimal();
    puts("1. Convertion to Biner");
    puts("2. Convertion to Oktal");
    puts("3. Converiton to Heksadesimal");
    puts("0. Exit");
    printf("Choice : ");
    fflush(stdin);
    scanf("%i", &choice);

    if(choice == 1)
        toBiner();
    else if(choice == 2)
        toOktal();
    else if(choice == 3)
        toHeksa();
    else{
        if(choice == 0)
            puts("Exit Program");
        else{
            puts("!----------------!");
            puts("Invalid Input");
            puts("!----------------!");
            return 1;
        }
    }
    printoutStack(&convertion);

    if(choice != 0)
        return 1;
    else
        return 0;
}

void inDecimal()
{
	printf("Input Decimal Number: ");
    fflush(stdin);
    scanf("%i", &decimal);
}

void initStack(stack *s)
{
    s->index = 0;
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

void push(itemType x, stack *s)
{
    if(isFull(s))
        puts("Stack Oveflow");
    else{
        s->data[s->index] = x;
        (s->index)++;
    }
}

itemType pop(stack *s)
{
    itemType temp;
    if(isEmpty(s))
	{
        puts("Stack Underflow");
        temp = '\0';
    }else
	{
        (s->index)--;
        temp = s->data[s->index];
    }

    return temp;
}

itemType intToChar(int x)
{
    switch(x)
	{
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default:
            puts("Not Decimal");
            exit(0);
    }
}

void printoutStack(stack *s)
{
    puts("===========================");
    while(convertion.index != 0){
        printf("%c", pop(&convertion));
    }
    puts("\n===========================");
}

void toBiner()
{
    initStack(&convertion);

    while(decimal != 0){
        push(intToChar(decimal % 2), &convertion);
        decimal /= 2;
    }
}

void toOktal()
{
    initStack(&convertion);

    while(decimal != 0)
	{
        push(intToChar(decimal % 8), &convertion);
        decimal /= 8;
    }
}

void toHeksa()
{
    initStack(&convertion);

    while(decimal != 0)
	{
        push(intToChar(decimal % 16), &convertion);
        decimal /= 16;
    }
}
