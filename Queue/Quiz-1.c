#include <stdio.h>
#include <stdlib.h>
#define MAX 255;

typedef struct simpul Node;
struct simpul
{
	int data;
	Node *next;
};

void sisip();
void hapus();
void urutan();
void tampil();
Node *p, *head, *tail, *hapusi, *phapus;
int nilai;

int main()
{
	char pilihan;
	int menu;
	
	do
	{
		puts("==========Pilihan Menu==========");
		printf("1. Sisip\n");
		printf("2. Hapus\n");
		printf("Pilihan	: ");
		fflush(stdin);	
		scanf("%i", &menu);
		switch(menu)
		{
			case 1:
				sisip();
				break;
			case 2:
				hapus();
				break;
			default:
				printf("Input Tidak Valid\n");	
		}
		printf("Ingin menginput data lagi? = ");
		fflush(stdin);
		scanf("%c", &pilihan);
	}while(pilihan == 'Y' || pilihan == 'y');
}

void sisip()
{
	p = (Node *)malloc(sizeof(Node));
	
	printf("Input Nilai : ");
	fflush(stdin);
	scanf("%i", &nilai);
	p->data = nilai;
	p->next = NULL;
	
	if(head==NULL)
		head = p;
	else
		p->next=head;
		
	head=p;
	urutan();
}

void hapus()
{
	int key;
	
	printf("Data yang ingin dihapus	: ");
	scanf("%i", &key);
	hapusi = head;
	
	if(hapusi->data == key)
	{
		hapusi = head;
	
		if(hapusi->next == NULL)
			head=NULL;
		else
			head=hapusi->next;
		free(hapusi);
		hapusi = NULL;
		urutan();
	}
	else
	{
		while(hapusi->data != key)
		{
			if(hapusi->next == NULL)
			{
				printf("Data yang ingin dihapus tidak ada\n");
				break;
			}
			else
			{
				phapus = hapusi;
				hapusi = hapusi->next;
			}
		}
	}
	urutan();
}

void urutan()
{
	Node *baca, *baca2;
	int tampung;
	
	baca=head;
	while(baca!=NULL)
	{
		baca2 = head;
		while(baca2!=NULL)
		{
			if(baca->data < baca2->data)
			{
				tampung = baca2->data;
				baca2->data = baca->data;
				baca->data = tampung;
			}	
			baca2 = baca2->next;
		}
		baca = baca->next;
	}
	tampil();
}

void tampil()
{
	Node *baca;
	
	baca=head;
	while(baca!=NULL)
	{
		printf("%i \n", baca->data);
		baca = baca->next;
	}
}
