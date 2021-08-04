#include <stdio.h>
#define max 10
#define M 100

//Matriks Beban
int Q[max][max] = { {M,1,2,M,M,M,M,M,M,M}, {2,M,M,2,M,M,M,M,M,M}, {M,3,M,M,1,M,M,M,M,M}, {M,3,M,M,M,2,M,M,M,M}, {M,M,5,M,M,M,3,M,M,M}, {M,M,M,M,4,M,M,2,M,M}, {M,M,M,4,M,M,M,M,2,M}, {M,M,M,M,M,M,M,M,2,3}, {M,M,M,M,M,M,5,M,M,2}, {9,M,M,M,M,M,M,M,M,M} };
//Matriks Jalur
int P[max][max] = { {0,1,1,0,0,0,0,0,0,0}, {1,0,0,1,0,0,0,0,0,0}, {0,1,0,0,1,0,0,0,0,0}, {0,1,0,0,0,1,0,0,0,0}, {0,0,1,0,0,0,1,0,0,0}, {0,0,0,0,1,0,0,1,0,0}, {0,0,0,1,0,0,0,0,1,0}, {0,0,0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,1,0,0,1}, {1,0,0,0,0,0,0,0,0,0} };
//Matriks Rute
int R[max][max] = { {M,0,0,M,M,M,M,M,M,M}, {0,M,M,0,M,M,M,M,M,M}, {M,0,M,M,0,M,M,M,M,M}, {M,0,M,M,M,0,M,M,M,M}, {M,M,0,M,M,M,0,M,M,M}, {M,M,M,M,0,M,M,0,M,M}, {M,M,M,0,M,M,M,M,0,M}, {M,M,M,M,M,M,M,M,0,0}, {M,M,M,M,M,M,0,M,M,0}, {0,M,M,M,M,M,M,M,M,M} };

//Fungsi Jalur
void warshall();
void cetak_rute();

//Stack
typedef int itemtype;
typedef struct
{
    itemtype data[M];
    int index;
}stack;

//Fungsi Stack
void inisialisasi_stack (stack *);
void push (itemtype, stack *);
itemtype pop (stack *);

//Variabel Global
stack temp;
int i, j, k, dari, tujuan;
char pilihan;

int main() 
{
    //Memanggil Fungsi Warshall untuk mencari Rute
    warshall();
    
    do
    {
    	//Menu Rute Halte Suroboyo Bus
		printf("<===============>RUTE HALTE SUROBOYO BUS<===============>\n");
		printf("1.  Halte UNESA\n");
		printf("2.  Halte Tunjungan Plaza\n");
		printf("3.  Halte Grand City\n");
		printf("4.  Halte UNAIR B\n");
		printf("5.  Halte KONI\n");
		printf("6.  Halte ITS\n");
		printf("7.  Halte Gubeng Kertajaya\n");
		printf("8.  Halte Delta\n");
		printf("9.  Halte Taman Makam Pahlawan\n");
		printf("10. Halte Graha Family\n");
		
		//Cetak Rute
	    puts("\nMencari Rute");
	    cetak_rute();
	    puts("");
	    
	    //Opsi Pengulangan
	    printf("Ingin Mencari Rute Lagi (Y/N)? : ");
	    fflush(stdin);
	    scanf("%c", &pilihan);
	}while(pilihan=='Y' || pilihan=='y');
}

void warshall()
{
    for (k = 0; k < max; k++) 
	{
        for (i = 0; i < max; i++) 
		{
            for (j = 0; j < max; j++) 
			{
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j]) 
				{
                    Q[i][j] = (Q[i][k] + Q[k][j]);
                    if (R[k][j] == 0)
                        R[i][j] = k+1;
                    else
                        R[i][j] = R[k][j];
                }
            }
        }
    }
}

void cetak_rute()
{
    inisialisasi_stack(&temp);

    printf("Dari Lokasi : ");
    scanf("%d", &dari);
    printf("Tujuan Perjalanan : ");
    scanf("%d", &tujuan);

    for (i = tujuan-1; i >= 0; i--) 
	{
        if (R[dari-1][i] != 0)
            push(R[dari-1][i], &temp);
        else if (R[dari-1][i]==0)
            break;
    }
    switch(dari)
    {
    	case 1:
    		printf("UNESA-");
    		break;
    	case 2:
    		printf("Tunjungan Plaza-");
    		break;
    	case 3:
    		printf("Grand City-");
    		break;
    	case 4:
    		printf("UNAIR B-");
    		break;
    	case 5:
    		printf("KONI-");
    		break;
    	case 6:
    		printf("ITS-");
    		break;
    	case 7:
    		printf("Gubeng Kertajaya-");
    		break;
    	case 8:
    		printf("Delta-");
    		break;
    	case 9:
    		printf("Taman Makam Pahlawan-");
    		break;
    	case 10:
    		printf("Graha Family-");
    		break;
    	default:
    		printf("Input Rute yang Anda Input Salah");
    		return;
	}

    for (j = temp.index; j > 0; j--) 
	{
		switch(pop(&temp))
	    {
	    	case 1:
	    		printf("UNESA-");
	    		break;
	    	case 2:
	    		printf("Tunjungan Plaza-");
	    		break;
	    	case 3:
	    		printf("Grand City-");
	    		break;
	    	case 4:
	    		printf("UNAIR B-");
	    		break;
	    	case 5:
	    		printf("KONI-");
	    		break;
	    	case 6:
	    		printf("ITS-");
	    		break;
	    	case 7:
	    		printf("Gubeng Kertajaya-");
	    		break;
	    	case 8:
	    		printf("Delta-");
	    		break;
	    	case 9:
	    		printf("Taman Makam Pahlawan-");
	    		break;
	    	case 10:
	    		printf("Graha Family-");
	    		break;
		}
    }
    switch(tujuan)
    {
    	case 1:
    		printf("UNESA");
    		break;
    	case 2:
    		printf("Tunjungan Plaza");
    		break;
    	case 3:
    		printf("Grand City");
    		break;
    	case 4:
    		printf("UNAIR B");
    		break;
    	case 5:
    		printf("KONI");
    		break;
    	case 6:
    		printf("ITS");
    		break;
    	case 7:
    		printf("Gubeng Kertajaya");
    		break;
    	case 8:
    		printf("Delta");
    		break;
    	case 9:
    		printf("Taman Makam Pahlawan");
    		break;
    	case 10:
    		printf("Graha Family");
    		break;
    	default:
    		printf("Input Rute yang Anda Input Salah");
    		return;
	}
}

void inisialisasi_stack (stack *s)
{
    s->index = 0;
}

void push(itemtype x, stack *s)
{
    if (s->index==M)
        puts("StackOverflow");
    else
	{
        ++(s->index);
        s->data[s->index] = x;
    }
}

itemtype pop(stack *s)
{
    itemtype tampung;

    if (s->index==0) 
	{
        puts("StackUnderflow");
        return 0;
    }
    else 
	{
        tampung = s->data[s->index];
        --s->index;
        return tampung;
    }
}
