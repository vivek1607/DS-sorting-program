#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char temp[100];
typedef struct node
{
        char Data[100];
        struct node *left,*right;
        int Height;
}Node;


int height(Node *T)
{
        int lh,rh;
        if(T==NULL)
                return(0);

        if(T->left==NULL)
                lh=0;
        else
                lh=1+T->left->Height;

        if(T->right==NULL)
                rh=0;
        else
                rh=1+T->right->Height;

        if(lh>rh)
                return(lh);

        return(rh);
}
Node * rotateright(Node *x)
{
        Node *y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->Height=height(x);
        y->Height=height(y);
        return(y);
}

Node * rotateleft(Node *x)
{
        Node *y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->Height=height(x);
        y->Height=height(y);

        return(y);
}

Node * RR(Node *T)
{
        T=rotateleft(T);
    printf("RR rotation done\n");
        return(T);
}
Node * LL(Node *T)
{
        T=rotateright(T);
    printf("LL rotation done\n");
        return(T);
}
Node * LR(Node *T)
{
        T->left=rotateleft(T->left);
    printf("RL rotation done\n");
        T=rotateright(T);
    printf("RR rotation done\n");

        return(T);
}
Node * RL(Node *T)
{
        T->right=rotateright(T->right);
    printf("RR rotation done\n");
        T=rotateleft(T);
    printf("RL rotation done\n");
        return(T);
}
int BF(Node *T)
{
        int lh,rh;
        if(T==NULL)
                return(0);

        if(T->left==NULL)
                lh=0;
        else
                lh=1+T->left->Height;

        if(T->right==NULL)
                rh=0;
         else
                rh=1+T->right->Height;

        return(lh-rh);
}

void inorder(Node *T)
{
        if(T!=NULL)
        {
                inorder(T->left);
                printf("%s(Bf=%d)\n",T->Data,BF(T));
                inorder(T->right);
        }
}

Node * insert(Node *T,char x[50])
{
        if(T==NULL)
        {
                T=(Node*)malloc(sizeof(Node));
                strcpy(T->Data,x);
                T->left=NULL;
                T->right=NULL;
        }
        else
            {

                if(strcmp(x,T->Data)>0)               // insert in right subtree
                {
                        T->right=insert(T->right,x);
                        int bf=BF(T);
                        if(bf==-2)
                                if(strcmp(x,T->right->Data)>0)
                                   T=RR(T);  //RR means right right imbalance,,,so we are performing right right rotation
                                else
                                   T=RL(T);  //RL means right left imbalance,,,so we are performing right left rotation
                }
                else
                {
                  if(strcmp(x,T->Data)<0)   //insert in left subtree
                  {
                        T->left=insert(T->left,x);
                        if(BF(T)==2)
                        if(strcmp(x,T->left->Data)<0)
                        T=LL(T);    //RR means left left imbalance , so we are performing left left rotation
                        else
                        T=LR(T);    //RL means left right imbalance , so we are performing left right rotation
                  }
                }

            }
        T->Height = height(T);
        return(T);
}

int main()
{
        Node *root=NULL;
        int x,n,i,choice;
        char k[50];
	struct Node *Rt;
        for(int a=1;a>0;a++)
	{
                printf("\n1)Create:");
                printf("\n2)Print:");
                printf("\n3)Quit:");
                printf("\n\nEnter Your Choice:");
                scanf("%d",&choice);
                if(choice==3)
		break;
		else
		{
		switch(choice)
                {
                        case 1: printf("\nEnter no. of elements:");
                                        scanf("%d",&n);
                                        printf("\nEnter tree Data:");
                                        root=NULL;
                                        for(i=0;i<n;i++)
                                        {
                                                scanf("%s",&k);
                                                root=insert(root,k);
						Rt=root;
                                        }
                                        break;

                        case 2: printf("\n\nInorder sequence:\n");
                                        inorder(root);
                                        printf("\n");
                                     break;
		}}}
}
