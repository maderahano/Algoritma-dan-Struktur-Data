#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10000000

//fungsi mode pengurutan
void ascending(int data[], int low, int mid, int high);
void descending(int data[], int low, int mid, int high);

//fungsi tambahan
void input();
void output();
void partition_a(int data[], int low, int high);
void partition_d(int data[], int low, int high);

//variabel global
int n, i, j;
int data[max], temp[max];
clock_t start, stop;

int main()
{
	int pil, awal, akhir;
	
	printf("<===============>MERGE SORTING<===============>\n\n");
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
					awal=0;
					akhir=n-1;
					start = clock();
					partition_a(data, awal, akhir);
					stop = clock();
					printf("\nTime : %lf\n", (double) (stop-start)/CLOCKS_PER_SEC);
					output();
					break;
				case 2:
					input();
					awal=0;
					akhir=n-1;
					start = clock();
					partition_d(data, awal, akhir);
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

void partition_a(int data[],int low,int high)
{
    int mid;

    if(low<high)
 	{
         mid=(low+high)/2;
         partition_a(data,low,mid);
         partition_a(data,mid+1,high);
         ascending(data, low, mid, high);
    }
}

void partition_d(int data[],int low,int high)
{
    int mid;

    if(low<high)
 	{
         mid=(low+high)/2;
         partition_d(data,low,mid);
         partition_d(data,mid+1,high);
         descending(data, low, mid, high);
    }
}

void ascending(int data[], int low, int mid, int high)
{
	int i, j, left_1, right_1, left_2, right_2;

	left_1 = low;
	right_1 = mid;
	left_2 = mid+1;
	right_2 = high;
	i = low;
	
    while((left_1<=right_1)&&(left_2<=right_2))
 	{
        if(data[left_1]<=data[left_2])
   		{
            temp[i] = data[left_1];
            left_1++;
        }else
   		{
            temp[i] = data[left_2];
            left_2++;
        }
        i++;
    }
    if(left_1>mid)
 	{
    	for(j=left_2;j<=high;j++)
   		{
            temp[i]=data[j];
            i++;
        }
    }else
 	{
        for(j=left_1;j<=mid;j++)
   		{
            temp[i]=data[j];
            i++;
        }
    }
    for(j=low;j<=high;j++)
	{
        data[j]=temp[j];
    }
}

void descending(int data[], int low, int mid, int high)
{
	int i, j, left_1, right_1, left_2, right_2;

	left_1 = low;
	right_1 = mid;
	left_2 = mid+1;
	right_2 = high;
	i = low;
	
    while((left_1<=right_1)&&(left_2<=right_2))
 	{
        if(data[left_1]>=data[left_2])
   		{
            temp[i] = data[left_1];
            left_1++;
        }else
   		{
            temp[i] = data[left_2];
            left_2++;
        }
        i++;
    }
    if(left_1>mid)
 	{
    	for(j=left_2;j<=high;j++)
   		{
            temp[i]=data[j];
            i++;
        }
    }else
 	{
        for(j=left_1;j<=mid;j++)
   		{
            temp[i]=data[j];
            i++;
        }
    }
    for(j=low;j<=high;j++)
	{
        data[j]=temp[j];
    }	
}
