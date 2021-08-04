#include <stdio.h>
#define max 5
#define M 100

//Data Matriks
int Q[max][max]; //Matriks Beban
int P[max][max]; //Matriks Jalur
int R[max][max]; //Matriks Rute

//Fungsi Matriks
void matriks_beban();
void matriks_jalur();
void matriks_rute();

//Fungsi Jalur
void input();
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
int i, j, k, n, dari, tujuan;

int main() 
{
	//Mengisi Data Matriks Terlebih Dahulu
    input();

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

void input()
{
    printf("Ukuran Node : ");
    scanf("%d", &n);
	
	//Menginput Matriks Beban
    puts("Input Matriks Beban");
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; ++j) 
		{
            if (i==j)
			{
                Q[i][j]=M;
            } else 
			{
                printf("Q[%d][%d] : ", i + 1, j + 1);
                scanf("%d", &Q[i][j]);
            }
        }
        puts("");
    }
    //Konversi Matrik Beban Menjadi Matriks Jalur
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; ++j) 
		{
            if (Q[i][j]==M)
                P[i][j]=0;
            else if (Q[i][j]!=M)
                P[i][j]=1;
        }
    }
    //Konversi Matriks Jalur Menjadi Matriks Rute
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; ++j) 
		{
            if (P[i][j]==0)
                R[i][j]=M;
            else
                R[i][j]=0;
        }
    }
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
