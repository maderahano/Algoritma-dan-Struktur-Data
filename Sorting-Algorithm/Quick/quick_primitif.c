#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10000000

//fungsi mode pengurutan
void ascending(int data[], int low, int high);
void descending(int data[], int low, int high);

//fungsi tambahan
void input();
void output();
void swap(int *,int *);

//variabel global
int n, i, j, temp, pivot;
int data[max];
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
		data[i]=rand();
		printf("%i ", data[i]);
	}
	puts("");
}

void output(void)
{
	printf("Data Setelah disorting : ");
	puts("");
	for(j=0;j<n;j++)
	{
		printf("%i ", data[j]);
	}
	puts("");
}

void swap(int *x, int *y)
{
	temp = *x;
	*x = *y;
	*y = temp;
}

void ascending(int data[], int low, int high)
{
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (data[i] <= data[pivot] && i <= high)
            {
                i++;
            }
            while (data[j] > data[pivot] && j >= low)
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

void descending(int data[], int low, int high)
{
	if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (data[i] >= data[pivot] && i <= high)
            {
                i++;
            }
            while (data[j] < data[pivot] && j >= low)
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
