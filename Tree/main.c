#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxstack 100

//Struct Binary Tree
typedef struct Node tree;
struct Node{
    char info;
    tree *kiri;
    tree *kanan;
    tree *parent;
};

//Transversal Function
void inorder(tree *);

//Function
void allocation();
void popoperator();
void popoperan1();
void popoperan2();

//Struct Stack
typedef struct {
    char data[maxstack];
    int indeks;
}stack;

//Stack Function
void inisialisasistack (stack *);
int isfull (stack *);
int isempty (stack *);
void push (char, stack *);
char pop (stack *);

//Global Variable
tree *root=NULL, *P, *Q, *new;
int i;
stack operator, operan;
char data[maxstack], cek, temp;

int main() {
    puts("====>Expression Tree<====");
    inisialisasistack(&operator);
    inisialisasistack(&operan);
    printf("Arithmatic Expression : ");
    fflush(stdin);
    gets(data);
    for (i=0; i<maxstack; i++){
        if (data[i]!=')'){
            temp=data[i];
            allocation();
            if((data[i] >= 65 && data[i] <= 90) || (data[i] >= 97 && data[i] <= 122))
                push(data[i], &operan);
            else
                push(data[i], &operator);
        }
        else if (data[i]==')'){
            popoperator();
            popoperan1();
            popoperan2();
            push(temp, &operan);
            pop(&operator);
        }
    }
    inorder(root);
    return 0;
}

void inisialisasistack (stack *s){
    s->indeks = 0;
}

int isfull (stack *s){
    return (s->indeks == maxstack);
}

int isempty (stack *s){
    return (s->indeks == 0);
}

void push(char x, stack *s){
    if (isfull(s))
        puts("stack penuh");
    else{
        ++(s->indeks);
        s->data[s->indeks] = x;
    }
}
char pop(stack *s){
    char tampung;

    if (isempty(s)) {
        puts("Stack kosong");
        return 0;
    }
    else {
        tampung = s->data[s->indeks];
        --s->indeks;
        return tampung;
    }
}

void allocation(){
    new = (tree *)malloc(sizeof(tree));

    new->kiri = NULL;
    new->kanan = NULL;
    new->parent = NULL;
}

void popoperator(){
    allocation();
    new->info = pop(&operator);
    root=new;
}

void popoperan1(){
    allocation();
    P=root;
    new->info=pop(&operan);
    P->kanan=new;
    root->kanan=P->kanan;
    root->kanan->parent=P;
}

void popoperan2(){
    allocation();
    P=root;
    new->info=pop(&operan);
    P->kiri=new;
    root->kiri=P->kiri;
    root->kiri->parent=P;
}

void inorder (tree *akar){
    if (akar!=NULL) {
        inorder(akar->kiri);
        printf("%c ", akar->info);
        inorder(akar->kanan);
    }
}
