#include <stdio.h>
#include <stdlib.h>

typedef struct Simpul Node;
struct Simpul {
    char op;
    Node *go_child1, *go_child2;
    Node *go_parent;
};

typedef struct{
    Node *leaves[50];
    int top;
}Stack;

Node *create_node(char);
void push(Stack *);
Node *pop(Stack *);
void prefix(Node *);
void infix(Node *);
void postfix(Node *);

Node *p = NULL;
Stack opt = { .top = 0 }, opd = { .top = 0 };

int main()
{
    int i;
    char expression[50];

    printf("Input operasi : ");
    fflush(stdin);
    gets(expression);
    fflush(stdin);
    for(i=0; expression[i] != '\0'; i++){
        if(expression[i] != ' ' && expression[i] != ')'){
            p = create_node(expression[i]);
            if((expression[i] >= 65 && expression[i] <= 90) || (expression[i] >= 97 && expression[i] <= 122)){
                push(&opd);
            } else {
                push(&opt);
            }
        } else if(expression[i] == ')'){
            p = pop(&opt);
            p->go_child2 = pop(&opd);
            p->go_child2->go_parent = p;
            p->go_child1 = pop(&opd);
            p->go_child1->go_parent = p;
            push(&opd);
            pop(&opt);
        }
    }
    p = pop(&opt);
    p->go_child2 = pop(&opd);
    p->go_child2->go_parent = p;
    p->go_child1 = pop(&opd);
    p->go_child1->go_parent = p;
    puts("\nNotasi Prefix:");
    prefix(p);
    puts("\n\nNotasi Infix:");
    infix(p);
    puts("\n\nNotasi Postfix:");
    postfix(p);
    return 0;
}

Node *create_node(char c){
    Node *p;

    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        puts("\nMemory Error!\n");
        exit(0);
    }
    p->go_child1 = NULL;
    p->go_child2 = NULL;
    p->go_parent = NULL;
    p->op = c;
    return p;
}

void push(Stack *s){
    s->leaves[s->top] = p;
    s->top += 1;
}

Node *pop(Stack *s){
    Node *temp;

    s->top -= 1;
    temp = s->leaves[s->top];
    return temp;
}

void prefix(Node *root){
    if(root == NULL)
        return;
    printf("%c", root->op);
    prefix(root->go_child1);
    prefix(root->go_child2);
}

void infix(Node *root){
    if(root == NULL)
        return;
    infix(root->go_child1);
    printf("%c", root->op);
    infix(root->go_child2);
}

void postfix(Node *root){
    if(root == NULL)
        return;
    postfix(root->go_child1);
    postfix(root->go_child2);
    printf("%c", root->op);
}
