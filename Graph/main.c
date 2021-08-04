#include <stdio.h>
#define max 5
#define M 100

//Matrix
int Q[max][max] = { {M,0,2,M,M}, {M,M,0,M,4}, {2,M,M,1,M}, {M,M,M,M,0}, {M,M,M,M,M} };
int P[max][max] = { {0,1,1,0,0}, {0,0,1,0,1}, {1,0,0,1,0}, {0,0,0,0,1}, {0,0,0,0,0} };
int R[max][max] = { {M,0,0,M,M}, {M,M,0,M,0}, {0,M,M,0,M}, {M,M,M,M,0}, {M,M,M,M,M} };

//Function
void warshall();

int main() {
    puts("===>Matriks Beban<===");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (Q[i][j]==100)
                printf("M\t");
            else
                printf("%d\t", Q[i][j]);
        }
        printf("\n");
    }

    puts("\n===>Matriks Jalur<===");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            printf("%d\t", P[i][j]);
        }
        printf("\n");
    }

    puts("\n===>Matriks Rute<===");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (Q[i][j]==100)
                printf("M\t");
            else
                printf("%d\t", R[i][j]);
        }
        printf("\n");
    }

    warshall();

    puts("\n===>Warshall Beban<===");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (Q[i][j]==100)
                printf("M\t");
            else
                printf("%d\t", Q[i][j]);
        }
        printf("\n");
    }

    puts("\n===>Warshall Jalur<===");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            printf("%d\t", P[i][j]);
        }
        printf("\n");
    }

    puts("\n===>Warshall Rute<===");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (Q[i][j]==100)
                printf("M\t");
            else
                printf("%d\t", R[i][j]);
        }
        printf("\n");
    }
}

void warshall(){
    for (int k = 0; k < max; k++) {
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j]) {
                    Q[i][j] = (Q[i][k] + Q[k][j]);
                    if (R[k][j] == 0)
                        R[i][j] = k;
                    else
                        R[i][j] = R[k][j];
                }
            }
        }
    }
}