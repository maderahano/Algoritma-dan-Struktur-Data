#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10000000

//fungsi pilihan
void ascending();
void descending();

//variabel global
int data[max], temp, n, i, j, p=0, perbandingan;
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
	printf("Input Jumlah Data	: ");
	scanf("%i", &n);
	puts("");
	
	printf("Sebelum Sorting : \n");
	for(i=0;i<n;i++)
	{
		data[i]=rand();
		printf("%i ", data[i]);
	}
	puts("");
	
	start = clock();
	for(i=1;i<n;i++)
	{
        temp = data[i];
        j = i-1;
        while((temp < data[j]) && (j >= 0))
		{
            data[j+1] = data[j];
            j=j-1;
            p++;
        }
        data[j+1] = temp;
    }
    stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
    
	printf("Setelah Sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%i ", data[i]);
	}
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
	printf("Input Jumlah Data	: ");
	scanf("%i", &n);
	puts("");

	printf("Sebelum Sorting : \n");
	for(i=0;i<n;i++)
	{
		data[i]=rand();
		printf("%i ", data[i]);
	}
	puts("");
	
	start = clock();
	for(i=1;i<n;i++)
	{
        temp = data[i];
        j = i-1;
        while((temp > data[j]) && (j >= 0))
		{
            data[j+1] = data[j];
            j=j-1;
            p++;
        }
        data[j+1] = temp;
    }
    stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
    
	printf("Setelah Sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%i ", data[i]);
	}
	puts("");
	if(p > 1)
		perbandingan = (n*(n-1))/2;
	else
		perbandingan = n-1;
	printf("Jumlah Perbandingan key (C) : %i", perbandingan);
	puts("");	
}
