#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
	int data;
	Node *next;
};

void insert_awal();
void insert_akhir();
void insert_before();
void insert_after();
void delete_awal();
void delete_akhir();
void delete_tertentu();
void tampil();
Node *p, *head = NULL, *tail = NULL, *before, *after, *pbef, *hapus, *phapus;
int nilai;

int main()
{
	int pilihan, menu;
	
	do
	{
	puts("==========PILIHAN MENU==========");
	printf("1. Insert Awal\n");
	printf("2. Insert Akhir\n");
	printf("3. Insert Before\n");
	printf("4. Insert After\n");
	printf("5. Delete Awal\n");
	printf("6. Delete Akhir\n");
	printf("7. Delete Tertentu\n");
	printf("Pilihan menu di atas = ");
	scanf("%i", &menu);
		switch(menu)
		{
			case 1:
			{
				insert_awal();
				break;	
			}
			case 2:
			{
				insert_akhir();
				break;
			}
			case 3:
			{
				insert_before();
				break;
			}
			case 4:
			{
				insert_after();
				break;
			}
			case 5:
			{
				delete_awal();
				break;	
			}
			case 6:
			{
				delete_akhir();
				break;
			}
			case 7:
			{
				delete_tertentu();
				break;
			}
			default:
				printf("Input pilihan tidak valid");
		}
		printf("Ingin memasukkan data lagi (y/t)? ");
		fflush(stdin);
		scanf("%c", &pilihan);
	}while(pilihan == 'y' || pilihan == 'Y');
}

void insert_awal()
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
	tampil();
}

void insert_akhir()
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
	{
		tail = head;
		while(tail->next != NULL)
			tail = tail->next;
	}
	
	tail->next=p;
	tail = tail->next;
	tampil();
}

void insert_before()
{
	int key;
	
	p = (Node *)malloc(sizeof(Node));
	printf("Input Key	: ");
	fflush(stdin);
	scanf("%i", &key);
	
	if(head->data==key)
		insert_awal();
	else
	{
		printf("Input Nilai : ");
		fflush(stdin);
		scanf("%i", &nilai);
		p->data = nilai;
		p->next = NULL;
		
		before=head;
		do
		{
			pbef = before;
			if(before->next==NULL)
				puts("Key tidak ada");
			else
				before = before->next;
		}while(before->data!=key);
		p->next = before;
		pbef->next = p;
		tampil();
	}
}

void insert_after()
{
	int key;
	
	p = (Node *)malloc(sizeof(Node));
	printf("Input Key	: ");
	fflush(stdin);
	scanf("%i", &key);
	printf("Input Nilai : ");
	fflush(stdin);
	scanf("%i", &nilai);
	p->data = nilai;
	p->next = NULL;
	
	after = head;
	while(after->data!=key)
	{
		if(after->next==NULL)
			puts("Key tidak ada");
		else
			after = after->next;
	}
	p->next = after->next;
	after->next = p;
	tampil();
}

void delete_awal()
{
	hapus = head;
	
	if(hapus->next == NULL)
		head=NULL;
	else
		head=hapus->next;
		
	free(hapus);
	hapus=NULL;
	tampil();
}

void delete_akhir()
{
	hapus = head;
	
	while(hapus->next!=NULL)
	{
		phapus=hapus;
		hapus=hapus->next;
	}
	
	phapus->next=NULL;
	
	free(hapus);
	hapus=NULL;
	tampil();
}

void delete_tertentu()
{
	int key;
	
	printf("Input Key	: ");
	scanf("%i", &key);
	hapus = head;
	
	if(hapus->data == key)
		delete_awal();
	else
	{
		while(hapus->data != key)
		{
			if(hapus->next == NULL)
				printf("Key Tidak Ada");
			else
			{
				phapus = hapus;
				hapus = hapus->next;
			}
		}
	}
	phapus->next = hapus->next;
	free(hapus);
	hapus = NULL;
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
