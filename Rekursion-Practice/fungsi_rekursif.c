#include <stdio.h>
#include <stdlib.h>

//fungsi menu
void menu();

//fungsi rekursif
int pil1(int );
int pil2(int );
int pil3(int );
int pil4(int );
int pil5(int ,int ,int );
int pil6(int );
int pil7(int );
int pil8(int );
int pil9(int );

int main()
{
	menu();
}

//fungsi menu
void menu()
{
	int pilih_1, hasil, n, i;
	char pilih_2;
	
	do
	{
		puts("===============>MENU<===============");
		printf("1. \n");
		printf("2. \n");
		printf("3. \n");
		printf("4. \n");
		printf("5. \n");
		printf("6. \n");
		printf("7. \n");
		printf("8. \n");
		printf("9. \n");
		printf("Pilih	: ");
		scanf("%i", &pilih_1);
		switch(pilih_1)
		{
			case 1:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil1(n);
				printf("Output	: %i", hasil);
				puts("");
				break;
			case 2:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil2(n);
				printf("Output	: %i", hasil);
				puts("");
				break;
			case 3:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil3(n);
				printf("Output	: %i", hasil);
				puts("");
				break;
			case 4:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil4(n);
				printf("Output	: %i", hasil);
				puts("");
				break;
			case 5:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil5(n, 0, 1);
				printf("Output	: %i\n", hasil);
				for(i=1; i<=n;i++)
				{
					printf("%i\t%i\n", i, pil5(n, 0, 1));
				}
				break;
			case 6:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil6(n);
				printf("\nOutput	: %i", hasil);
				break;
			case 7:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil7(n);
				printf("\nOutput	: %i", hasil);
				break;
			case 8:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil8(n);
				printf("Output	: %i", hasil);
				break;
			case 9:
				printf("Input	: ");
				scanf("%i", &n);
				hasil = pil9(n);
				printf("Output	: %i", hasil);
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

//fungsi-fungsi pilihan
int pil1(int x)
{
	if(x == 0)
		return 0;
	else if(x == 1)
		return 4;
	else 
		return pil1(x-1) + 4*x;
}

int pil2(int x)
{
	int i;
	
	for(i=x;i>=0;i--)
	{
		if(x < 1)
			return 0;
		else if(x == 1)
			return 8;
		else if(i>1 && i%2==0)
			return pil2(x-1) + (x*4);
		else if(i>1 && i%2!=0)
			return pil2(x-1) + (x*8);	
	}
}

int pil3(int x)
{
	int i;
	
	for(i=x;i>=0;i--)
	{
		if(x < 1)
			return 0;
		else if(x == 1)
			return 1;
		else if(i>1 && i%3==0)
			return pil3(x-1)+2;
		else if(i>1 && i%3!=0)
			return pil3(x-1)+1;
	}	
}

int pil4(int x)
{
	int i;
	
	for(i=x;i>=0;i--)
	{
		if(x < 1)
			return 0;
		else if(x == 1)
			return 1;
		else if(i>1 && i%4==0)
			return pil3(x-1)-1;
		else if(i>1 && i%4!=0)
			return pil3(x-1)+1;
	}	
}

int pil5(int x, int y, int z)
{
	if(x<1)
	{
		return 0;	
	}
	else if(y == z)
	{
		return (0 + pil5(x-1, 0, z+1));
	}else
	{
		return (1 + pil5(x-1, y+1, z));
	}
	
}

int pil6(int x)
{
	if(x<=0)
	{
		printf("\n");
	}else
	{
		if(x%2!=0)
		{
			pil6(x-1);
			printf("%i\t",x);
		}else
		{
			pil6(x-1);
			printf("\t");
		}	
	}	
}

int pil7(int x)
{
	if(x==1)
	{
		printf("1\t");
	}else
	{
		if(x%2==0)
		{
			pil7(x-1);
			printf("*\t");
		}else if(x%2!=0)
		{
			pil7(x-1);
			printf("%i\t", x-x/2);
		}
	}
}

int pil8(int x)
{
	if(x<1)
		return 0;
	else if(x==1)
		return 1;
	else if(x%3==0)
		return pil8(x-1);
	else
		return x+pil8(x-1);
}

int pil9(int x)
{
	if(x<1)
		return 0;
	else if(x==1)
		return 1;
	else if(x%2==0)
		return pil9(x-1);
	else
		return pil9(x-1)*x;
}
