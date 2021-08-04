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
product data[max], temp;

//fungsi pilihan
void ascending();
void descending();

//variabel global
int n, i, j, p=0, perbandingan;
clock_t start, stop;

int main()
{
	int pil;
	
	printf("<===============>INSERTION SORTING<===============>\n\n");
	while(1)
	{
		do
		{
			printf("<---------->MENU<---------->\n");
			printf("1. Ascending\n");
			printf("2. Desdending\n");
			printf("3. Exit\n");
			printf("Pilihan	: ");
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
					printf("Input Pilihan Menu yang Anda Pilih Tidak Ada\n");
					printf("Silahkan Dicoba lagi\n");
			}
			fflush(stdin);
		}while(pil!=1 && pil!=2 && pil!=3);
	}
}

void ascending()
{
	printf("<---------->Pengurutan Secara Ascending<---------->\n\n");
	printf("Input Jumlah Produk	: ");
	scanf("%i", &n);
	puts("");
	
	printf("Sebelum Sorting : \n");
	for(i=0;i<n;i++)
	{
		data[i].kode_produk=rand();
		printf("Kode Produk	: %i\n", data[i].kode_produk);
		fflush(stdin);
		printf("Produk		: ");
		gets(data[i].produk);
	}
	puts("");
	
	start = clock();
	for(i=0;i<n;i++)
	{
        for(j=0;j<n-1;j++)
        {
            while((data[j].kode_produk > data[j+1].kode_produk) && (j >= 0))
			{
	            temp = data[j];
				data[j] = data[j+1];
	            data[j+1] = temp;
	            p++;
	        }	
		}
    }
    stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
    
	printf("Data Setelah disorting : \n");
	printf("------------------------\n");
	printf("Kode Produk\t Produk\n");
	printf("------------------------\n");
	for(j=0;j<n;j++)
	{
		printf("%i\t\t %s\n", data[j].kode_produk, data[j].produk);
	}
	printf("------------------------\n");
	puts("");
	if(p > 1)
		perbandingan = (n*(n-1))/2;
	else
		perbandingan = n-1;
	printf("Jumlah Perbandingan key (C) : %i", perbandingan);
	puts("");
}

void descending()
{
	printf("<---------->Pengurutan Secara Descending<---------->\n\n");
	printf("Input Jumlah Produk	: ");
	scanf("%i", &n);
	puts("");
	
	
	printf("Sebelum Sorting : \n");
	for(i=0;i<n;i++)
	{
		data[i].kode_produk=rand();
		printf("Kode Produk	: %i\n", data[i].kode_produk);
		fflush(stdin);
		printf("Produk		: ");
		gets(data[i].produk);
	}
	puts("");
	
	start = clock();
	for(i=0;i<n;i++)
	{
        for(j=0;j<n-1;j++)
        {
            while((data[j].kode_produk < data[j+1].kode_produk) && (j >= 0))
			{
	            temp = data[j];
				data[j] = data[j+1];
	            data[j+1] = temp;
	            p++;
	        }	
		}
    }
    stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
    
	printf("Data Setelah disorting : \n");
	printf("------------------------\n");
	printf("Kode Produk\t Produk\n");
	printf("------------------------\n");
	for(j=0;j<n;j++)
	{
		printf("%i\t\t %s\n", data[j].kode_produk, data[j].produk);
	}
	printf("------------------------\n");
	puts("");
	if(p > 1)
		perbandingan = (n*(n-1))/2;
	else
		perbandingan = n-1;
	printf("Jumlah Perbandingan key (C) : %i", perbandingan);
	puts("");	
}
