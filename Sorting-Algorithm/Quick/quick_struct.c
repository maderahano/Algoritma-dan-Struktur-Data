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

//fungsi mode pengurutan
void ascending(product data[], int low, int high);
void descending(product data[], int low, int high);

//fungsi tambahan
void input();
void output();
void swap(product *,product *);

//variabel global
int n, i, j, pivot;
clock_t start, stop;

int main()
{
	int pil;
	
	printf("<===============>QUICK SORTING<===============>\n\n");
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
					input();
					start = clock();
					ascending(data, 0, n-1);
					stop = clock();
					printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
					output();
					break;
				case 2:
					input();
					start = clock();
					descending(data, 0, n-1);
					stop = clock();
					printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
					output();
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
	
	printf("Data Sebelum disorting : ");
	puts("");
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
	puts("");
}

void swap(product *x, product *y)
{
	temp = *x;
	*x = *y;
	*y = temp;
}

void ascending(product data[], int low, int high)
{
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (data[i].kode_produk <= data[pivot].kode_produk && i <= high)
            {
                i++;
            }
            while (data[j].kode_produk > data[pivot].kode_produk && j >= low)
            {
                j--;
            }
            if (i < j)
            {
            	swap(&data[i], &data[j]);
            }
        }
        swap(&data[j], &data[pivot]);
        ascending(data, low, j - 1);
        ascending(data, j + 1, high);
    }
}

void descending(product data[], int low, int high)
{
	if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (data[i].kode_produk >= data[pivot].kode_produk && i <= high)
            {
                i++;
            }
            while (data[j].kode_produk < data[pivot].kode_produk && j >= low)
            {
                j--;
            }
            if (i < j)
            {
            	swap(&data[i], &data[j]);
            }
        }
        swap(&data[j], &data[pivot]);
        descending(data, low, j - 1);
        descending(data, j + 1, high);
    }
}
