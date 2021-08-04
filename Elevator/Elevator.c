#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 20

//Jadi project yang direvisi adalah jika user menginput kurang dari 1 dan lebih dari 10
//maka inputannya salah, dan melakukan perulangan lagi.

void beggining(void );
void potition(void );
void beg_direction(void );
void up(void );
void down(void );
void output(void );

char again;
int lift, i, j, h=0, k, g=0, flag, passenger;
int start[max], destination[max], leave[max], move[2*max];

int main()
{
    puts("This Building has 10 floors");
    beggining();
    beg_direction();
    output();
    return 0;
}

void beggining(void )
{
	//di bagian ini saya menambaha do while untuk input posisi awal dari elevator. jika kuran dari 1 dan lebih dari 10 maka harus diulang sampai benar.
    do
	{		
		printf("Input the beggining potition of elevator = ");
		scanf("%d", &lift);
		move[h]=lift;
		h++;
		if(lift < 1 || lift > 10)
	    {
		    printf("Your Input Number Elevator is Wrong!\n");
		    printf("Please Try Again!\n");	        	
		}
	}while(lift < 1 || lift > 10);

	for (passenger=0;passenger<10;passenger++)
	{
		//Penambahan bagian do while ini untuk inputan posisi awal dari penumpang, jika terjadi suatu kondisi user salah meninput nomornya.
		do
		{
			printf("Input the beggining potition elevator of passenger %d = ", passenger+1);
	        scanf("%d", &start[passenger]);
	        if(start[passenger] < 1 || start[passenger] > 10)
	        {
	        	printf("Your Input of Begginning Potition Elevator of passenger is Invalid!\n");
		        printf("Please Try Again!\n");
			}
		}while(start[passenger] < 1 || start[passenger] > 10);
		//untuk bagian disini sama dengan bagian sebelumnya, yang ini untuk tujuan destinani penumpang.
		do
		{
	        printf("Input the destination potition elevator of passenger = ");
	        scanf("%d", &destination[passenger]);
	        if(destination[passenger] < 1 || destination[passenger] > 10)
	        {
	        	printf("Your Input of Destination Potition Elevator of passenger is Invalid!\n");
		        printf("Please Try Again!\n");
			}
		}while(destination[passenger] < 1 || destination[passenger] > 10);
        printf("Is there more passenger?(y/n)");
	    fflush(stdin);
        scanf("%c", &again);
        fflush(stdin);
        if (again == 'N'|| again == 'n')
            break;
	}
}

void beg_direction(void )
{
    for (i=0;i<=passenger;i++)
	{
        if (i==0)
            j=i;
        else
		{
            if (abs(lift - start[i])<abs(lift - start[j]))
            	j=i;
        }
    }
    if (start[j]>lift)
        up();
    else
        down();
}

void up(void )
{
    printf("Elevator Up\n");
    flag=0;
    
    for (;lift<=10;lift++)
	{
        for (j=0;j<=passenger;j++)
		{
            if (lift == start[j])
			{
                move[h]=lift;
                h++;
                leave[g]=destination[j];
                g++;
                potition();
            }
        }
        for (j=0;j<g;j++)
		{
            if (leave[j]==lift)
			{
                move[h]=lift;
                h++;
                potition();
            }
        }
    }
    for (i=0;i<=passenger;i++)
	{
        if (start[i] != (-1))
		{
            flag=1;
            break;
        }
    }
    for (i=0;i<g;i++)
	{
        if (leave[i] != (-1)){
            flag=1;
            break;
        }
    }
    if (flag == 1)
        down();
    else
        printf("Elevator Stop\n");
}

void down(void)
{
    puts("Elevator Down");
    flag=0;
    
    for (;lift>0;lift--)
	{
        for (j=0;j<=passenger;j++)
		{
            if (lift == start[j]){
                move[h]=lift;
                h++;
                leave[g]=destination[j];
                g++;
                potition();
            }
        }
        for (j=0;j<g;j++)
		{
            if (leave[j]==lift){
                move[h]=lift;
                h++;
                potition();
            }
        }
    }
    for (i=0;i<=passenger;i++)
	{
        if (start[i] != (-1))
		{
            flag=1;
            break;
        }
    }
    for (i=0;i<g;i++)
	{
        if (leave[i] != (-1))
		{
            flag=1;
            break;
        }
    }
    if (flag == 1)
        up();
    else
        printf("Elevator Stop\n");
}

void potition(void )
{
    printf("Elevator in the potition floor %d\n", lift);
    printf("Is there more passenger?(y/n) = ");
    fflush(stdin);
    scanf("%c", &again);
    fflush(stdin);
    while (again=='Y'|| again=='y')
	{
		//di bagian ini, saya tambahkan do while karena, ada perintah input posisi penumpang.
		//jika user salah meninputkan nomernya, maka user bisa mengulanginya lagi dengan benar.
        do
        {
			printf("Input the passenger potition = ");
	        scanf("%d", &start[passenger]);
			if(start[passenger] < 1 || start[passenger] > 10)
	        {
	        	printf("Your Input The Potition Elevator of passenger is Invalid!\n");
		        printf("Please Try Again!\n");
			}	
		}while(start[passenger] < 1 || start[passenger] > 10);
		passenger++;
		//di bagian ini sama dengan sebelumnya, perintah ini disuruh untuk menginput destinasi penumpang.
		do
		{
	        printf("Destination Floors = ");
	        scanf("%d", &destination[passenger]);
			if(destination[passenger] < 1 || destination[passenger] > 10)
	        {
	        	printf("Your Input of Destination Elevator of passenger is Invalid!\n");
		        printf("Please Try Again!\n");
			}			
		}while(destination[passenger] < 1 || destination[passenger] > 10);


	    printf("Is there more passenger?(y/n) = ");
	    fflush(stdin);
	    scanf("%c", &again);
    }
    for (k=0;k<=passenger;k++)
	{
        if (start[k]==lift){
            start[k]=-1;
            leave[g]=destination[k];
            g++;
        }
    }
    for (k=0;k<g;k++)
	{
        if (leave[k]==lift)
            leave[k]=-1;
    }
}

void output(void )
{
    printf("Elevator Lanes = \n");
    for (k=0;k<h;k++)
	{
        if (k==0)
            printf("%d", move[k]);
        else
            printf(" - %d", move[k]);
    }
}
