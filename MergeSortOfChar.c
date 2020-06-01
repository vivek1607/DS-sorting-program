#include <stdio.h>
#include<stdlib.h>
void Merge(char A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    char B[100];
    while(i<=mid && j<=h)
    {

        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else
        {
            B[k++]=A[j++];
        }
    }

    //remaining element from array1 or array2 are move to B array
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    //copy all the elements from array B to array A
    for(i=l;i<=h;i++)
        A[i]=B[i];
}


void MergeSort(char A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    char A[]={"polynomial"},n=10,i=0;


    MergeSort(A,0,n-1);

    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%c ",A[i]);
    }
    char B[]={"testcase"},l=8,x=0;


    MergeSort(B,0,l-1);

    printf("\n");
    for(x=0;x<8;x++)
    {
        printf("%c ",B[x]);
    }

    return 0;
}
