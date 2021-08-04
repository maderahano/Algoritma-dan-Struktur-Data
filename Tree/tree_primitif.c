#include <stdio.h>
#include <stdlib.h>

typedef int type_info;
typedef struct node tree;
struct node
{
 type_info info;
 tree *right;
 tree *left;
};
tree *p, *q, *news, *root=NULL;

//fungsi tambahan
void menu();
void input();
void allocation();

//fungsi transversal
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);

//variabel global
int data;
int chc_1, chc_2;

int main()
{
	printf("<===============>MENU BINARY SEARCH TREE<===============>\n\n");
	while(1)
	{
		do 
		{
	        fflush(stdin);
	        menu();
	    } while (chc_1!=1 && chc_1!=2 && chc_1!=3);	
	}
    return 0;
}

void menu()
{
	puts("1. Fill Data");
    puts("2. Traversal");
    puts("3. Exit");
    printf("Your choice [1/2/3] : ");
    scanf("%i", &chc_1);
    switch (chc_1) 
	{
        case 1:
            input();
            break;
        case 2:
            puts("Traversal Method");
            puts("1. Preorder");
			puts("2. Inorder");
            puts("3. Postorder");
            printf("Your choice [1/2/3] : ");
            scanf("%d", &chc_2);
            switch (chc_2) 
			{
				case 1:
					printf("Output (PreOrder) : ");
                    preorder(root);
                    puts("");
                    break;
                case 2:
                	printf("Output (InOrder) : ");
                    inorder(root);
                    puts("");
                    break;
                case 3:
                	printf("Output (PostOrder) : ");
                    postorder(root);
                    puts("");
                    break;
                default:
                    printf("Try again\n");
                    break;
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Try Again\n");
            break;
    }
}

void  input()
{
		allocation();
		if(root==NULL)
		{
			root=news;
		}else
		{
			q=root;
			p=root;
			while((q!=NULL)&&(news->info!=p->info))
			{
				p=q;
				if(news->info>p->info) { q=p->right; }
				else { q=p->left; }
			}
			if(p->info!=news->info)
			{
				if(p->info>news->info) { p->left=news; }
				else { p->right=news; }
			}else {puts ("There are Duplicate Value");}
		}
}

void allocation()
{
	fflush(stdin);
	printf("Input Value :");
	scanf("%i",&data);
	news = (tree *)malloc(sizeof(tree));
		
	if(news==NULL)
	{ 
		printf("Failed to Allocation\n");
	  	exit(0); 
	}else
	{ 
		news->info=data;
		news->right=NULL;
		news->left=NULL;
	}
}

void preorder(tree *root)
{
	if(root!=NULL)
	{
		printf("%i",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%i",root->info);
		inorder(root->right);
	}
}

void postorder(tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%i",root->info);
	}
}
