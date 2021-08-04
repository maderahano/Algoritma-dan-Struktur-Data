#include <stdio.h>
#include <stdlib.h>
#define max 5

struct queue
{
	int data[max];
	int count, front, rear;	
}q;

void menu();
void initialization_queue();
void enqueue();
void dequeue();
int isFull();
int isEmpety();
void output();

int main()
{
	menu();
}

void menu()
{
	int choice_1, choice_2;
	
	initialization_queue();
	while(1)
	{
		do
		{
			puts("===============MENU===============");
			puts("1. Enqueue");
			puts("2. Dequeue");
			puts("3. Display");
			puts("4. Exit");
			printf("Input Your Choice	: ");
			fflush(stdin);
			scanf("%i", &choice_1);
			
			switch(choice_1)
			{
				case 1:
					enqueue();
					break;
				case 2:
					dequeue();
					break;
				case 3:
					output();
					break;
				case 4:
					exit(0);
				default:
					puts("Your input choice number is Invalid!");
				puts("Please, try input again");
			}
		}while(choice_1 != 1 && choice_1 != 2 && choice_1 != 3 && choice_1 != 4);
	}
}

void initialization_queue()
{
	q.count = 0;
	q.front = 0;
	q.rear	 = 0;
}

int isFull()
{
	return q.count == max;
}

int isEmpety()
{
	return q.count == 0;
}

void enqueue()
{
	int x;
	
	if(isFull())
		puts("Queue Overflow");
	else
	{
		if(q.rear == max)
		{
			q.rear = (q.rear+1) % max;
			printf("Insert the element	: ");
			fflush(stdin);
			scanf("%i", &x);
			q.data[q.rear] = x;
			q.rear++;
			q.count++;	
		}else
		{
			printf("Insert the element	: ");
			fflush(stdin);
			scanf("%i", &x);
			q.data[q.rear] = x;
			q.rear++;
			q.count++;	
		}	
	}
}

void dequeue()
{
	int temp;
	
	if(isEmpety())
	{
		puts("Queue Underflow!");
	}else
	{
		if(q.front == max)
		{
			q.front = (q.front+1)%max;
			temp = q.data[q.front];
			q.front++;
			q.count--;
		}else
		{
			temp = q.data[q.front];
			q.front++;
			q.count--;	
		}
	}
}

void output()
{
	int i;
	
	if(q.front < q.rear)
	{
		for(i=q.front;i<q.rear;i++)
			printf("%i ", q.data[i]);
		puts("");
	}
	else
	{
		for(i=q.front;i<max;i++)
			printf("%i ", q.data[i]);
		q.front = (q.front+1)%max;
		for(i=q.front;i<q.rear;i++)
			printf("%i ", q.data[i]);
		puts("");
	}
}
