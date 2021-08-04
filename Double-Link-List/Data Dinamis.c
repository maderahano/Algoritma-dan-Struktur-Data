#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
	int data, umur ,nilai;
	char nama[200];
	Node *next, *prev;
};

void insert_awal();
void insert_akhir();
void insert_before();
void insert_after();
void delete_awal();
void delete_akhir();
void delete_tertentu();
void tampil();
void alokasi();
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
	alokasi();
	
	if(head==NULL)
		head = p;
	else
	{
		p->next=head;
		head->prev = p;	
		head = p;
	}
		
	tampil();
}

void insert_akhir()
{ 
	alokasi();
	
	if(head==NULL)
		head = p;
	else
	{
		tail = head;
		while(tail->next != NULL)
			tail = tail->next;
	}
	
	p->prev = tail;
	tail->next=p;
	tail = p;
	tampil();
}

void insert_before()
{
	int key;

	printf("Input Key	: ");
	fflush(stdin);
	scanf("%i", &key);
	
	if(head->data==key)
		insert_awal();
	else
	{
		alokasi();
		
		before=head;
		do
		{
			if(before->next==NULL)
			{
				puts("Key tidak ada");
				exit(0);	
			}
			else
				before = before->next;
		}while(before->data!=key);
		p->next = before;
		p->prev = before->prev;
		before->prev->next = p;
		before->prev = p;
		tampil();
	}
}

void insert_after()
{
	int key;
	
	printf("Input Key	: ");
	fflush(stdin);
	scanf("%i", &key);
	alokasi();
	
	after = head;
	while(after->data!=key)
	{
		if(after->next==NULL)
		{
			puts("Key tidak ada");
			exit(0);	
		}
		else
			after = after->next;
	}
	if(after->next!=NULL)
	{
		p->next = after->next;
		p->prev = after;
		after->next->prev = p;
		after->next = p;	
	}
	else
	{
		p->prev = after;
		after->next = p;
	}
	tampil();
}

void delete_awal()
{
	hapus = head;
	
	if(head == NULL)
	{
		puts("Linked List kosong");
		insert_awal();	
	}else if (head != NULL)
	{
		head = hapus->next;
		free(hapus);
		hapus=NULL;
		if(head == NULL)
			puts("Linked List kosong");
		else
			tampil();		
	}

}

void delete_akhir()
{
	hapus = head;
	
	if(head == NULL)
	{
		puts("Linked List kosong");
		insert_awal();	
	}else if (hapus->next != NULL)
	{
		while(hapus->next != NULL)
		{
			hapus = hapus->next;
		}
		if(hapus->next == NULL)
			delete_awal();
		else
		{
			hapus->prev->next = hapus->next;
			free(hapus);
			hapus=NULL;
			tampil();			
		}		
	}
}

void delete_tertentu()
{
	int key;
	
	hapus = head;
	if(head == NULL)
	{
		puts("Linked List kosong");
		insert_awal();	
	}else if(head!=NULL)
	{
		printf("Input Key	: ");
		scanf("%i", &key);	
		
		while(hapus->data!=key)
		{
			if(hapus->next==NULL)
			{
				puts("Key tidak ada");
				break;
			}else
				hapus = hapus->next;
		}
	}
	
	if((hapus->next==NULL) && (hapus->prev==NULL))
	{
		head = hapus->next;
		free(hapus);
		hapus = NULL;
		if(head==NULL)
			puts("Linked List kosong");
		else
			tampil();
	}else if((hapus->next!=NULL) && (hapus->prev==NULL))
	{
		head = hapus->next;
		free(hapus);
		hapus = NULL;
		tampil();	
	}else if((hapus->next!=NULL) && (hapus->prev!=NULL))
	{
		hapus->prev->next = hapus->next;
		hapus->next->prev = hapus->prev;
		free(hapus);
		hapus=NULL;
		tampil();
	}else if((hapus->next==NULL) && (hapus->prev!=NULL))
	{
		hapus->prev->next = NULL;
		free(hapus);
		hapus = NULL;
		tampil();
	}
}

void tampil()
{
	Node *baca;
	
	baca=head;
	while(baca!=NULL)
	{
		printf("%i\t %s\t %i\t %i \n", baca->data, baca->nama, baca->umur, baca->nilai);
		baca = baca->next;
	}
}

void alokasi()
{
	p = (Node *)malloc(sizeof(Node));
	
	if(p==NULL)
		exit (0);
	else
	{
		p->next = NULL;
		p->prev = NULL;
		printf("Input No Absen : ");
		fflush(stdin);
		scanf("%i", &p->data);
		printf("Input Nama : ");
		fflush(stdin);
		gets(p->nama);
		printf("Input Umur : ");
		fflush(stdin);
		scanf("%i", &p->umur);
		printf("Input Nilai : ");
		fflush(stdin);
		scanf("%i", &p->nilai);
	}	
}
