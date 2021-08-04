#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10000000

//data struct
typedef struct data_produk
{
	int kode_produk;
	char produk[max];
}product;
product data[max], temp1;

//fungsi-fungsi pilihan
void ascending(void);
void descending(void);

//fungsi support
void input(void);
void output(void);
void swap(product *,product *);

//variabel global
int n, i, j, temp2, temp3, perbandingan;
clock_t start, stop;

//fungsi main menu
int main()
{
	int pil;
	
	printf("<===============>SELECTION SORTING<===============>\n\n");
	while(1)
	{
		do
		{
			printf("<---------->MENU<---------->\n");
			printf("1. Ascending\n");
			printf("2. Descending\n");
			printf("3. Exit\n");
			printf("Pilihan Anda : ");
			scanf("%i", &pil);
			
			
			switch(pil)
			{
				case 1:
					ascending();
					break;
				case 2:
					descending();
					break;
				case 3:
					exit(0);
				default:
					printf("Input pilihan anda, tidak ada dalam menu kami\n");
					printf("Silahkan dicoba lagi\n");
			}
			fflush(stdin);
		}while(pil != 1 && pil != 2 && pil != 3);
	}
}

void input(void)
{
	printf("Input jumlah data : ");
	scanf("%i", &n);
	
	printf("Data Sebelum disorting : \n");
	for(i=0;i<n;i++)
	{
		data[i].kode_produk=rand();
		printf("Kode Produk	: %i\n", data[i].kode_produk);
		fflush(stdin);
		printf("Produk		: ");
		gets(data[i].produk);
	}
	puts("");
}

void output(void)
{
	printf("Data Setelah disorting : \n");
	printf("------------------------\n");
	printf("Kode Produk\t Produk\n");
	printf("------------------------\n");
	for(j=0;j<n;j++)
	{
		printf("%i\t\t %s\n", data[j].kode_produk, data[j].produk);
	}
	printf("------------------------\n");
	perbandingan = (n*(n-1))/2;
	printf("Jumlah Perbandingan Key (C) : %i", perbandingan);
	puts("");
}

void swap(product *x, product *y)
{
	temp1 = *x;
	*x = *y;
	*y = temp1;
}

void ascending(void)
{
	printf("<---------->Pengurutan Secara Ascending<---------->\n\n");
	input();
	start = clock();
	for(i=0;i<n-1;i++)
	{
		temp2 = i;
		for(j=i+1;j<n;j++)
		{
			if(data[j].kode_produk < data[temp2].kode_produk)
				temp2 = j;	
		}
		swap(&data[temp2], &data[i]);
	}
	stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
	output();
}

void descending(void)
{
	printf("<---------->Pengurutan Secara Descending<---------->\n\n");
	input();
	start = clock();
	for(i=0;i<n-1;i++)
	{
		temp3 = i;
		for(j=i+1;j<n;j++)
		{
			if(data[j].kode_produk > data[temp3].kode_produk)
				temp3 = j;	
		}
		swap(&data[temp3], &data[i]);
	}
	stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
	output();	
}
