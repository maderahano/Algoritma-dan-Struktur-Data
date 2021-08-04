#include <stdio.h>
#define max 5
#define M 100

//Matrix
int Q[max][max] = { {M,1,3,M,M}, {M,M,1,M,5}, {3,M,M,2,M}, {M,M,M,M,1}, {M,M,M,M,M} };
int TQ[max];
int R[max];

//Path Function
void dijkstra();
void findpath();

//Stack
typedef int itemtype;
typedef struct{
    itemtype data[M];
    int index;
}stack;

//Stack Function
void inisialisasistack (stack *);
void push (itemtype, stack *);
itemtype pop (stack *);

//Queue
struct queue{
    int data[max];
    int count;
    int front;
    int rear;
};

//Queue Function
void inisialisasi(struct queue *);
int empty(struct queue *);
int full(struct queue *);
void enqueue(int ,struct queue *);
int dequeue(struct queue *);

//Function
void input();
void output();

//Global Variable
stack temp;
struct queue antrian;
int from, dest, current;
int i, j, k, l, m, n, o, p, q, find;

int main() {
    input();
    output();
    dijkstra();
    findpath();
}

void input(){
    printf("Size Matriks : ");
    scanf("%d", &n);

    printf("Node From : ");
    scanf("%d", &from);
    printf("Node Destination : ");
    scanf("%d", &dest);

    //Menyimpan Beban Total Minimal ke Matriks TQ
    for (k = 0; k < n; k++) {
        TQ[k] = Q[from][k];
        if (TQ[k] == TQ[from-1])
            TQ[k] = 0;
        else
            TQ[k] = M;
    }

    //Menyimpan Rute yang Ditempuh ke Matriks R
    for (m = 0; m < n; m++) {
        R[m] = TQ[m];
        if (R[m] == R[from-1])
            R[m] = 0;
        else
            R[m] = -1;
    }
}

void output(){
    puts("\n===>Matriks Beban<===");
    for (p = 0; p < n; p++) {
        for (j = 0; j < n; j++) {
            if (Q[p][j]==100)
                printf("M\t");
            else
                printf("%d\t", Q[p][j]);
        }
        printf("\n");
    }

    puts("\nMatriks TQ");
    for (l = 0; l < n; l++) {
        printf("%d\t", TQ[l]);
    }

    puts("\nMatriks R");
    for (o = 0; o < n; o++) {
        printf("%d\t", R[o]);
    }
}

void dijkstra(){
    inisialisasi(&antrian);
    enqueue(from, &antrian);
    while (antrian.count != 0){
        current = dequeue(&antrian)-1;
        i=0;
        while (i < n){
            if (Q[current][i] != M){
                if (Q[current][i] + TQ[current] < TQ[i]){
                    TQ[i] = Q[current][i] + TQ[current];
                    R[i] = current+1;
                    for (j = 0; j < n; j++) {
                        if (antrian.data[j]!=i)
                            find=0;
                        else
                            find=1;
                    }
                    if (i+1 != from && find==0) {
                        enqueue(i + 1, &antrian);
                    }
                }
            }
            i++;
        }
    }

    puts("\n\nDijkstra Matriks TQ");
    for (l = 0; l < n; l++) {
        printf("%d\t", TQ[l]);
    }

    puts("\nDijkstra Matriks R");
    for (q = 0; q < n; q++) {
        printf("%d\t", R[q]);
    }
}

void findpath(){
    puts("\n\nRute");
    inisialisasistack(&temp);

    for (j = dest-1; j >= 0 && R[j] != 0; j--) {
        push(R[j], &temp);
    }

    while (temp.index != 0){
        printf("%d\t", pop(&temp));
    }

    printf("%d", dest);
}

void inisialisasistack (stack *s){
    s->index = 0;
}

void push(itemtype x, stack *s){
    if (s->index==M)
        puts("stack penuh");
    else{
        ++(s->index);
        s->data[s->index] = x;
    }
}

itemtype pop(stack *s){
    itemtype tampung;

    if (s->index==0) {
        puts("Stack kosong");
        return 0;
    }
    else {
        tampung = s->data[s->index];
        --s->index;
        return tampung;
    }
}

void inisialisasi(struct queue *q){
    q->count=0;
    q->front=0;
    q->rear=0;
}

int empty(struct queue *q){
    return (q->count==0);
}

int full(struct queue *q){
    return (q->count==max);
}

void enqueue(int var, struct queue *q){
    if (full(q)){
        puts("Queue is full");
    }
    else {
        q->data[q->rear]=var;
        q->rear=(q->rear+1)%max;
        ++q->count;
    }
}

int dequeue(struct queue *q){
    int tampung = 0;

    if(empty(q)){
        puts("Queue is empty");
    }
    else {
        tampung=q->data[q->front];
        q->data[q->front]=0;
        q->front=(q->front+1)%max;
        --q->count;
    }
    return tampung;
}
