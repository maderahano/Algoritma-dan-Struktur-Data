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
int data[max], n, i, j, temp, did_swap=1;
int jum_ban, jum_tuk, jum_ges;
clock_t start, stop;

//fungsi main menu
int main()
{
	int pil;
	
	printf("<===============>BUBBLE SORTING<===============>\n\n");
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
	if(did_swap == 0)
	{
		jum_ban = n-1;
		jum_tuk = 0;
		jum_ges = 0;
		printf("Jumlah Perbandingan Key (C)	: %i\n", jum_ban);
		printf("Jumlah Swap			: %i\n", jum_tuk);
		printf("Jumlah Pergeseran (M)		: %i\n", jum_ges);
	}else
	{
		jum_ban = (n*(n-1))/2;
		jum_tuk = (n*(n-1))/2;
		jum_ges = (3*n*(n-1))/2;
		printf("Jumlah Perbandingan Key (C)	: %i\n", jum_ban);
		printf("Jumlah Swap			: %i\n", jum_tuk);
		printf("Jumlah Pergeseran (M)		: %i\n", jum_ges);	
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
	for(i=n-1;i>0;i--)
	{
		did_swap = 0;
		for(j=0;j<i;j++)
		{
			if(data[j] > data[j+1])
			{
				swap(&data[j], &data[j+1]);
				did_swap = 1;	
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
	for(i=n-1;i>0;i--)
	{
		did_swap = 0;
		for(j=0;j<i;j++)
		{
			if(data[j] < data[j+1])
			{
				swap(&data[j], &data[j+1]);
				did_swap = 1;	
			}
		}
	}
	stop = clock();
	printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
	output();	
}
