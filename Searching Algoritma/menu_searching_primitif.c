#include <stdio.h>
#include <stdlib.h>
#define max 10000

//fungsi metode searching
void sequential_search_1();
void sequential_search_2();
void binary_search();

//fungsi pengurutan
void quick_sort(int data[], int low, int high);

//fungsi tambahan
void input();
void output_sorting();
void swap(int *,int *);

//variabel global
int n, i, j, temp, pivot, key, find;
int data[max];

int main()
{
	int pil;
	
	printf("<===============>MENU SEARCHING ALGORITHM<===============>\n\n");
	while(1)
	{
		do
		{
			printf("<---------->MENU<---------->\n");
			printf("1. Sequential Search (Unsorted Array)\n");
			printf("2. Sequential Search (Sorted Array)\n");
			printf("3. Binary Search\n");
			printf("4. Exit\n");
			printf("Pilihan Anda : ");
			scanf("%i", &pil);
			
			switch(pil)
			{
				case 1:
					input();
					sequential_search_1();
					break;
				case 2:
					input();
					sequential_search_2();
					break;
				case 3:
					input();
					binary_search();
					break;
				case 4:
					exit(0);
				default:
					printf("Input pilihan anda, tidak ada dalam menu kami\n");
					printf("Silahkan dicoba lagi\n");
			}
			fflush(stdin);
		}while(pil != 1 && pil != 2 && pil != 3 && pil != 4);
	}
}

void input(void)
{
	printf("Input jumlah data : ");
	scanf("%i", &n);
	
	printf("Data : ");
	puts("");
	for(i=0;i<n;i++)
	{
		data[i]=rand();
		printf("%i ", data[i]);
	}
	puts("");
}

void output_sorting(void)
{
	printf("Sorting Data : ");
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

void quick_sort(int data[], int low, int high)
{
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (data[i] <= data[pivot] && i <= high)
                i++;
            while (data[j] > data[pivot] && j >= low)
                j--;
            if (i < j)
            	swap(&data[i], &data[j]);
        }
        swap(&data[j], &data[pivot]);
        quick_sort(data, low, j - 1);
        quick_sort(data, j + 1, high);
    }
}

void sequential_search_1()
{
	i = 0;
	find = 0;
	
	printf("Target Data : ");
	scanf("%i", &key);
	while(find == 0 && i < n)
	{
		if(data[i] == key)
			find = 1;
		else
			i++;
	}
	if(find == 1)
		printf("%i adalah indeks dari data yang dicari yaitu %i\n\n", i, data[i]);
	else
		printf("Data tidak ditemukan!\n\n");
	
}

void sequential_search_2()
{
	quick_sort(data, 0, n-1);
	output_sorting();
	
	i = 0;
	find = 0;	
	printf("Target Data : ");
	scanf("%i", &key);
	while(find == 0 && i < n)
	{
		if(data[i] == key)
			find = 1;
		else
			i++;
	}
	if(find == 1)
		printf("%i adalah indeks dari data yang dicari yaitu %i\n\n", i, data[i]);
	else
		printf("Data tidak ditemukan!\n\n");
}

void binary_search()
{
	int L, M, R;
	
	quick_sort(data, 0, n-1);
	output_sorting();
	
	L=0; 
	R=n-1;
	find = 0;
	printf("Target Data : ");
	scanf("%i", &key);
	while(L <= R && find == 0)
	{
		M = (L+R)/2;
		
		if(data[M] == key)
			find = 1;
		if(key < data[M])
			R = M-1;
		if(key > data[M])
			L = M+1;
	}
	if(find == 1)
		printf("%i adalah indeks dari data yang dicari yaitu %i\n\n", M, data[M]);
	else
		printf("Data tidak ditemukan!\n\n");
}
