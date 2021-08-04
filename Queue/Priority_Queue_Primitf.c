#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
	int data;
	Node *next;
};

void initialization_queue();
int empty();
void enqueue();
int dequeue();
void output();
void sisipawal();
void sisipakhir();
void sisipbefore();

Node *p, *head, *tail, *hapus, *before, *pbef;

int data, tampung, pil;
char lagi;

int main() 
{
	int choice_1;
	
	puts("Queue Linked List Sort Ascending");
	
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
	return 0;
}

void initialization_queue()
{
	head=NULL;
	tail=NULL;
}

int empty()
{
	return(head==NULL);
}

void enqueue()
{
	p=(Node *)malloc(sizeof(Node));
	
	printf("Input data : ");
	scanf("%i", &data);
	if (head == NULL) 
	{
	sisipawal();
	tail = head;
	while (tail->next != NULL)
	tail= tail->next;
	}else if (data < head->data)
	{
		sisipawal();
	}else if (data > tail->data)
	{
		sisipakhir();
	}else
	{
		sisipbefore();
	}
	fflush(stdin);
}

int dequeue()
{
	p=(Node *)malloc(sizeof(Node));
	
	if(empty())
	{
	puts("Queue is empty");
	}else
	{
		tampung=head->data;
		hapus=head;
		head=hapus->next;
		free(hapus);
		hapus=NULL;
		if(head==NULL)
		tail=NULL;
	}
	return tampung;
}

void output()
{
	Node *baca;
	baca=head;
	while(baca!=NULL)
	{
		printf("%d ", baca->data);
		baca=baca->next;
	}
	puts("");
}

void sisipawal()
{
	p->data = data;
	p->next = NULL;
	
	if(head==NULL)
		head=p;
	else
		p->next=head;
	head=p;
}
void sisipakhir()
{
	p->data = data;
	p->next = NULL;
	
	if(head == NULL)
		head=p;
	else
	{
		tail = head;
		while (tail->next != NULL)
			tail= tail->next;
	}
	tail->next=p;
	tail=tail->next;
}
void sisipbefore()
{
	p->data=data;
	p->next=NULL;
	before=head;
	
	do
	{
		pbef=before;
		before=before->next;
	}while(before->data < p->data);
	p->next=before;
	pbef->next=p;
}
