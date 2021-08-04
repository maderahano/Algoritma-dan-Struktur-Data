#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10000

//data struct
typedef struct pruduct_data
{
	int kode_produk, jumlah_produk;
	char produk[max];
}product;
product data[max], temp, data_unsorted[max];

//fungsi metode searching
void sequential_search_1();
void sequential_search_2();
void binary_search();

//fungsi pengurutan
void quick_sort(product data[], int low, int high);

//fungsi tambahan
void menu();
void input();
void output_unsorted();
void output_sorted();
void swap(product *,product *);

//variabel global
int n, i, j, pivot, find, key_i, result;
int pil_1, pil_2, pil_3, pil_4, pil_5, pil_6;
char key_c[100];

int main()
{
	printf("<===============>MENU SEARCHING ALGORITHM<===============>\n\n");
	input();
    do 
	{
        fflush(stdin);
        menu();
        fflush(stdin);
    }while (pil_1 != 4);
}

void menu()
{
	while(1)
	{
		do
		{
			printf("<---------->MENU<---------->\n");
			printf("1. Tampilkan Data\n");
			printf("2. Sequential Search\n");
			printf("3. Binary Search\n");
			printf("4. Exit\n");
			printf("Pilihan Anda [1/2/3/4] : ");
			scanf("%i", &pil_1);
			
			switch(pil_1)
			{
				case 1:
					puts("Bentuk Data");
		            puts("1. Tidak Terurut");
		            puts("2. Terurut Berdasarkan Field_1");
		            printf("Pilihan anda [1/2] : ");
		            scanf("%i", &pil_2);
		            switch (pil_2) 
					{
		                case 1:
		                	printf("Data UnSorted : \n");
		                    output_unsorted();
		                    break;
		                case 2:
		                	printf("Data Sorted : \n");
		                    quick_sort(data, 0, n-1);
							output_sorted();
		                    break;
		                default:
		                    printf("Try Again\n");
		                    break;
		            }
		            break;
				case 2:
					puts("Bentuk Data");
		            puts("1. Tidak Terurut");
		            puts("2. Terurut Berdasarkan Field_1");
		            printf("Pilihan anda [1/2] : ");
		            scanf("%i", &pil_3);
		            switch (pil_3) 
					{
		                case 1:
		                    puts("Pencarian Berdasarkan");
		                    puts("1. Field_1 (Kode Produk)");
		                    puts("2. Field_2 (Produk)");
		                    puts("3. Field_3 (Jumlah Produk)");
		                    printf("Pilihan anda [1/2/3] : ");
		                    scanf("%i", &pil_4);
		                    switch (pil_4) 
							{
		                        case 1:
		                            sequential_search_1();
		                            break;
		                        case 2:
		                            sequential_search_1();
		                            break;
		                        case 3:
		                            sequential_search_1();
		                            break;
		                        default:
		                            printf("Try again\n");
		                            break;
		                    }
		                    break;
		                case 2:
		                    puts("Pencarian Berdasarkan");
		                    puts("1. Field_1 (Kode Produk)");
		                    puts("2. Field_2 (Produk)");
		                    puts("3. Field_3 (Jumlah Produk)");
		                    printf("Pilihan anda [1/2/3] : ");
		                    scanf("%i", &pil_5);
		                    switch (pil_5) 
							{
		                        case 1:
		                            sequential_search_2();
		                            break;
		                        case 2:
		                            sequential_search_2();
		                            break;
		                        case 3:
		                            sequential_search_2();
		                            break;
		                        default:
		                            printf("Try again\n");
		                            break;
		                    }
		                    break;
		                default:
		                    printf("Try Again\n");
		                    break;
		            }
		            break;
				case 3:
					puts("Pencarian Berdasarkan");
		            puts("1. Field_1 (Kode Produk)");
		            puts("2. Field_2 (Produk)");
		            puts("3. Field_3 (Jumlah Produk)");
		            printf("Pilihan anda [1/2/3] : ");
		            scanf("%i", &pil_6);
		            switch (pil_6)  
					{
		                case 1:
		                    binary_search();
		                    break;
		                case 2:
		                    binary_search();
		                    break;
		                case 3:
		                    binary_search();
		                    break;
		                default:
		                    printf("Try again\n");
		                    break;
		            }
		            break;
				case 4:
					exit(0);
				default:
					printf("Input pilihan anda, tidak ada dalam menu kami\n");
					printf("Silahkan dicoba lagi\n");
			}
			fflush(stdin);
		}while(pil_1 != 1 && pil_1 != 2 && pil_1 != 3 && pil_1 != 4);
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
		data[i].kode_produk=rand();
		printf("Kode Produk	: %i\n", data[i].kode_produk);
		fflush(stdin);
		printf("Produk		: ");
		fflush(stdin);
		gets(data[i].produk);
		printf("Jumlah Produk	: ");
		fflush(stdin);
		scanf("%i", &data[i].jumlah_produk);
	}
	for(i=0;i<n;i++)
	{
		data_unsorted[i].kode_produk = data[i].kode_produk;
		strcpy(data_unsorted[i].produk, data[i].produk);
		data_unsorted[i].jumlah_produk = data[i].jumlah_produk;
	}
	puts("");
}

void output_unsorted(void)
{
	printf("-------------------------------------\n");
	printf("Kode Produk\t Produk\t Jumlah Produksi\n");
	printf("-------------------------------------\n");
	for(j=0;j<n;j++)
	{
		printf("%i\t\t %s\t %i\n", data_unsorted[j].kode_produk, data_unsorted[j].produk, data_unsorted[j].jumlah_produk);
	}
	printf("-------------------------------------\n");
	puts("");
}

void output_sorted(void)
{
	printf("-------------------------------------\n");
	printf("Kode Produk\t Produk\t Jumlah Produksi\n");
	printf("-------------------------------------\n");
	for(j=0;j<n;j++)
	{
		printf("%i\t\t %s\t %i\n", data[j].kode_produk, data[j].produk, data[j].jumlah_produk);
	}
	printf("-------------------------------------\n");
	puts("");
}

void swap(product *x, product *y)
{
	temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort(product data[], int low, int high)
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
        quick_sort(data, low, j - 1);
        quick_sort(data, j + 1, high);
    }
}

void sequential_search_1()
{
	i = 0;
	key_i = 0;
	find = 0;
	result = 0;
	
	if(pil_4 == 1)
	{
		printf("Target Data (Kode Produk) : ");
		scanf("%i", &key_i);
		while(find == 0 && i < n)
		{
			if(data_unsorted[i].kode_produk == key_i)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data kode produk yang dicari yaitu %i\n\n", i, data_unsorted[i].kode_produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}else if(pil_4 == 2)
	{
		printf("Target Data (Nama Produk) : ");
		fflush(stdin);
		gets(key_c);
		while(find == 0 && i < n)
		{
			result = strcmp(data_unsorted[i].produk, key_c);
			if(result == 0)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data nama produk yang dicari yaitu %s\n\n", i, data_unsorted[i].produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}else
	{
		printf("Target Data (Jumlah Produk) : ");
		scanf("%i", &key_i);
		while(find == 0 && i < n)
		{
			if(data_unsorted[i].jumlah_produk == key_i)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data jumlah produk yang dicari yaitu sebesar %i\n\n", i, data_unsorted[i].jumlah_produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}
}

void sequential_search_2()
{	
	i = 0;
	key_i = 0;
	find = 0;
	result = 0;
	
	if(pil_5 == 1)
	{
		printf("Target Data (Kode Produk) : ");
		scanf("%i", &key_i);
		while(find == 0 && i < n)
		{
			if(data[i].kode_produk == key_i)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data kode produk yang dicari yaitu %i\n\n", i, data[i].kode_produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}else if(pil_5 == 2)
	{
		printf("Target Data (Nama Produk) : ");
		fflush(stdin);
		gets(key_c);
		while(find == 0 && i < n)
		{
			result = strcmp(data[i].produk, key_c);
			if(result == 0)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data nama produk yang dicari yaitu %s\n\n", i, data[i].produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}else
	{
		printf("Target Data (Jumlah Produk) : ");
		scanf("%i", &key_i);
		while(find == 0 && i < n)
		{
			if(data[i].jumlah_produk == key_i)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data jumlah produk yang dicari yaitu sebesar %i\n\n", i, data[i].jumlah_produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}
}

void binary_search()
{
	int L, M, R;
	
	L=0; 
	R=n-1;
	find = 0;
	result = 0;
	key_i = 0;
	
	if(pil_6 == 1)
	{
		printf("Target Data (Kode Produk) : ");
		scanf("%i", &key_i);
		while(L <= R && find == 0)
		{
			M = (L+R)/2;
			
			if(data[M].kode_produk == key_i)
				find = 1;
			if(key_i < data[M].kode_produk)
				R = M-1;
			if(key_i > data[M].kode_produk)
				L = M+1;
		}
		if(find == 1)
			printf("%i adalah indeks dari data yang dicari yaitu %i\n\n", M, data[M].kode_produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}else if(pil_6 == 2)
	{
		printf("Target Data (Nama Produk) : ");
		fflush(stdin);
		gets(key_c);
		while(find == 0 && i < n)
		{
			result = strcmp(data[i].produk, key_c);
			if(result == 0)
				find = 1;
			else
				i++;
		}
		if(find == 1)
			printf("%i adalah indeks dari data yang dicari yaitu %s\n\n", M, data[M].produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}else
	{
		printf("Target Data (Jumlah Produk) : ");
		scanf("%i", &key_i);
		while(L <= R && find == 0)
		{
			M = (L+R)/2;
			
			if(data[M].jumlah_produk == key_i)
				find = 1;
			if(key_i < data[M].jumlah_produk)
				R = M-1;
			if(key_i > data[M].jumlah_produk)
				L = M+1;
		}
		if(find == 1)
			printf("%i adalah indeks dari data yang dicari yaitu %i\n\n", M, data[M].jumlah_produk);
		else
			printf("Data tidak ditemukan!\n\n");
	}
}
