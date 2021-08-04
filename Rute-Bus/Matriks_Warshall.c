#include <stdio.h>
#define max 10
#define M 100

//Matriks Beban
int Q[max][max] = { {M,1,2,M,M,M,M,M,M,M}, {2,M,M,2,M,M,M,M,M,M}, {M,3,M,M,1,M,M,M,M,M}, {M,3,M,M,M,2,M,M,M,M}, {M,M,5,M,M,M,3,M,M,M}, {M,M,M,M,4,M,M,2,M,M}, {M,M,M,4,M,M,M,M,2,M}, {M,M,M,M,M,M,M,M,2,3}, {M,M,M,M,M,M,5,M,M,2}, {9,M,M,M,M,M,M,M,M,M} };
//Matriks Jalur
int P[max][max] = { {0,1,1,0,0,0,0,0,0,0}, {1,0,0,1,0,0,0,0,0,0}, {0,1,0,0,1,0,0,0,0,0}, {0,1,0,0,0,1,0,0,0,0}, {0,0,1,0,0,0,1,0,0,0}, {0,0,0,0,1,0,0,1,0,0}, {0,0,0,1,0,0,0,0,1,0}, {0,0,0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,1,0,0,1}, {1,0,0,0,0,0,0,0,0,0} };
//Matriks Rute
int R[max][max] = { {M,0,0,M,M,M,M,M,M,M}, {0,M,M,0,M,M,M,M,M,M}, {M,0,M,M,0,M,M,M,M,M}, {M,0,M,M,M,0,M,M,M,M}, {M,M,0,M,M,M,0,M,M,M}, {M,M,M,M,0,M,M,0,M,M}, {M,M,M,0,M,M,M,M,0,M}, {M,M,M,M,M,M,M,M,0,0}, {M,M,M,M,M,M,0,M,M,0}, {0,M,M,M,M,M,M,M,M,M} };

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
	puts("<--------------->MATRIKS SEBELUM MENCARI RUTE<--------------->\n");
	matriks_beban();
	matriks_jalur();
    matriks_rute();

    //Memanggil Fungsi Warshall untuk mencari Rute
    puts("");
    warshall();

	//Mencetak 3 Matriks Setelah Mencari Rute
	puts("<--------------->MATRIKS SETELAH MENCARI RUTE<--------------->\n");
    matriks_beban();
	matriks_jalur();
    matriks_rute();
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

