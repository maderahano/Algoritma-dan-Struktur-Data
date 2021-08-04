#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10000000

//fungsi-fungsi pilihan
void ascending(void);
void descending(void);

//fungsi support
void input(void);
void output(void);
void swap(int *,int *);

//variabel global
int data[max], n, i, j, temp1, temp2, temp3, perbandingan;
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
		data[i]=rand();
		printf("%i ", data[i]);
	}
	puts("");
}

void output(void)
{
	printf("Data Setelah disorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%i ", data[i]);
	}
	puts("");
	perbandingan = (n*(n-1))/2;
	printf("Jumlah Perbandingan Key (C) : %i", perbandingan);
	puts("");
}

void swap(int *x, int *y)
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
			if(data[j] < data[temp2])
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
			if(data[j] > data[temp3])
				temp3 = j;	
		}
		swap(&data[temp3], &data[i]);
	}
	stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
	output();	
}
