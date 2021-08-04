#include <stdio.h>
#define max 5
#define M 100

//Matriks
int Q[max][max] = { {M,1,3,M,M}, {M,M,1,M,5}, {3,M,M,2,M}, {M,M,M,M,1}, {M,M,M,M,M} }; //Matriks Beban
int P[max][max] = { {0,1,1,0,0}, {0,0,1,0,1}, {1,0,0,1,0}, {0,0,0,0,1}, {0,0,0,0,0} }; //Matriks Jalur
int R[max][max] = { {M,0,0,M,M}, {M,M,0,M,0}, {0,M,M,0,M}, {M,M,M,M,0}, {M,M,M,M,M} }; //Matriks Rute

//Fungsi Matriks
void matriks_beban();
void matriks_jalur();
void matriks_rute();

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

int main() 
{
	//Mencetak 3 Matriks yang Telah Diinputkan
	matriks_beban();
	matriks_jalur();
    matriks_rute();

    //Memanggil Fungsi Warshall untuk mencari Rute
    warshall();

	//Mencetak 3 Matriks Setelah Mencari Rute
    matriks_beban();
	matriks_jalur();
    matriks_rute();
	
	//Cetak Rute
    puts("\nMencari Rute");
    cetak_rute();
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
    printf("%d\t", dari);

    for (j = temp.index; j > 0; j--) 
	{
        printf("%d\t", pop(&temp));
    }
    printf("%d", tujuan);
}

void matriks_beban()
{
	puts("===>Matriks Beban<===");
    for (i = 0; i < max; i++) 
	{
        for (j = 0; j < max; j++) 
		{
            if (Q[i][j]==100)
                printf("M\t");
            else
                printf("%d\t", Q[i][j]);
        }
        printf("\n");
    }
}

void matriks_jalur()
{
	puts("\n===>Matriks Jalur<===");
    for (i = 0; i < max; i++) 
	{
        for (j = 0; j < max; j++) 
		{
            printf("%d\t", P[i][j]);
        }
        printf("\n");
    }
}

void matriks_rute()
{
	puts("\n===>Matriks Rute<===");
    for (i = 0; i < max; i++) 
	{
        for (j = 0; j < max; j++) 
		{
            if (Q[i][j]==100)
                printf("M\t");
            else
                printf("%d\t", R[i][j]);
        }
        printf("\n");
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
