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
int data[max], n, i, j, k, temp;
clock_t start, stop;

//fungsi main menu
int main()
{
	int pil;
	
	printf("<===============>SHELL SORTING<===============>\n\n");
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
	
	printf("Data Sebelum disorting : ");
	for(i=0;i<n;i++)
	{
		data[i]=rand();
		printf("%i ", data[i]);
	}
	puts("");
}

void output(void)
{
	printf("Data Setelah disorting : ");
	for(i=0;i<n;i++)
	{
		printf("%i ", data[i]);
	}
	puts("");
}

void swap(int *x, int *y)
{
	temp = *x;
	*x = *y;
	*y = temp;
}

void ascending(void)
{
	printf("<---------->Pengurutan Secara Ascending<---------->\n\n");
	input();
	start = clock();
	for(i=n/2;i>0;i/=2)
	{
		for(j=i;j<n;j++)
		{
			for(k=j-i;k>=0;k-=i)
			{
				if(data[k] > data[k+i])
					swap(&data[k], &data[k+i]);	
			}
		}
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
	for(i=n/2;i>0;i/=2)
	{
		for(j=i;j<n;j++)
		{
			for(k=j-i;k>=0;k-=i)
			{
				if(data[k] < data[k+i])
					swap(&data[k], &data[k+i]);	
			}
		}
	}
	stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
	output();	
}
