#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *num,int l,int r);
void merge(int *num,int l,int m,int r);
int main()
{
    int len;
    printf("How many numbers you want: ");
    scanf("%d",&len);
    int *num;
    num=(int*)malloc(sizeof(int)*len);
    int i;
    for(i=0;i<len;i++)
    {
        printf("Write a number: ");
        scanf("%d",&num[i]);
    }
    mergeSort(num,0,len-1);
    for(i=0;i<len;i++)
    {
        printf("%d",num[i]);
    }
}

void mergeSort(int *num,int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=l+(r-l)/2;
        mergeSort(num,l,mid);
        mergeSort(num,mid+1,r);
        merge(num,l,mid,r);
    }
}

void merge(int *num,int l,int m,int r)
{
    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=r-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=num[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=num[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            num[k]=L[i];
            i++;
        }
        else
        {
            num[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        num[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        num[k]=R[j];
        j++;
        k++;
    }
}