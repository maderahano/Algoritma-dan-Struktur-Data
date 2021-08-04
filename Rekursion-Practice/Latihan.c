#include <stdio.h>
#include <stdlib.h>

//fungsi main
void menu();

//fungsi-fungsi soal
int soal_1(int );
int soal_2(int );

int main()
{
	menu();
}

void menu()
{
	int pilih_1, hasil, n, i;
	char pilih_2;
	
	do
	{
		puts("===============>MENU<===============");
		printf("1. \n");
		printf("2. \n");
		printf("Pilih	: ");
		scanf("%i", &pilih_1);
		switch(pilih_1)
		{
			case 1:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = soal_1(n);
				printf("Output	: %i", hasil);
				puts("");
				break;
			case 2:
				printf("Input	: ");
				scanf("%i", &n);
				soal_2(n);
				puts("");
				break;
			default:
				printf("Input yang anda pilih salah\n");
				printf("Silahkan dicoba lagi\n");
		}
		puts("");
		fflush(stdin);
		printf("Lagi?(y/t)	: ");
		pilih_2 = getchar();
	}while(pilih_2 == 'Y' || pilih_2 == 'y');
	printf("\n===============>Terima Kasih<===============\n");	
}

int soal_1(int x)
{
	if(x==1)
		return 2;
	else if(x%2==0)
		return soal_1(x-1)-1;
	else if(x%2==1)
		return soal_1(x-2)+2;
}

int soal_2(int x)
{
	if(x==1)
	{
		printf("*\t");
	}else
	{
		if(x%2==0)
		{
			soal_2(x-1);
			printf("%i\t", 2*x-3);
		}else if(x%2!=0)
		{
			soal_2(x-1);
			printf("*\t");
		}
	}
}
