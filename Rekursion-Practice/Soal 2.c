#include <stdio.h>
#include <stdlib.h>

int persegi(int );

int main()
{
	int n, h;
	
	printf("===============INPUT BILANGAN===============\n");
	printf("Input	: ");
	scanf("%i", &n);
	h = persegi(n);
	printf("Output	: %i", h);	
}

int persegi(int x)
{
	if(x == 0)
		return 0;
	else if(x == 1)
		return 8;
	else
		return x*persegi(x-1) + 8*(x-2);
}
