#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5

typedef struct data
{
	int nrp;
	char nama[20];	
}mahasiswa;
mahasiswa informasi[max];

void menu();
void enqueue();
void dequeue();
int isFull();
int isEmpety();
void output();

int count=0, front=0, rear=0;

int main()
{
	menu();
}

void menu()
{
	int choice_1, choice_2;
	
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

void enqueue()
{
	if(count == max)
		puts("Queue Overflow");
	else
	{
		if(rear == max)
		{
			rear = (rear+1) % max;
			printf("Input NRP	: ");
			fflush(stdin);
			scanf("%i", &informasi[rear].nrp);
			printf("Insert Name	: ");
			fflush(stdin);
			gets(informasi[rear].nama);
			rear++;
			count++;	
		}else
		{
			printf("Input NRP	: ");
			fflush(stdin);
			scanf("%i", &informasi[rear].nrp);
			printf("Insert Name	: ");
			fflush(stdin);
			gets(informasi[rear].nama);
			rear++;
			count++;	
		}	
	}
}

void dequeue()
{
	int number;
	char temp_name[20];
	
	if(count == 0)
	{
		puts("Queue Underflow!");
	}else
	{
		if(front == max)
		{
			front = (front+1)%max;
			number = informasi[front].nrp;
			strcpy(temp_name, informasi[front].nama);
			informasi[front].nrp = 0;
			strcpy(informasi[front].nama, "");
			front++;
			--count;
		}else
		{
			number = informasi[front].nrp;
			strcpy(temp_name, informasi[front].nama);
			informasi[front].nrp = 0;
			strcpy(informasi[front].nama, "");
			front++;
			--count;	
		}
	}
}

void output()
{
	int i;
	
	printf("NRP\t Nama\n");
	if(front < rear)
	{
		for(i=front;i<rear;i++)
			printf("%i\t %s\n", informasi[i].nrp, informasi[i].nama);
		puts("");
	}else
	{
		for(i=front;i<max;i++)
			printf("%i\t %s\n", informasi[i].nrp, informasi[i].nama);
		front = (front+1)%max;
		for(i=front;i<rear;i++)
			printf("%i\t %s\n", informasi[i].nrp, informasi[i].nama);
		puts("");
	}
}
