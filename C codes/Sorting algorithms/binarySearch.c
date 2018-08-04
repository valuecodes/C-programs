#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    printf("How many numbers you want in an array: ");
    scanf("%d",&len);
    int *num;
    num=(int*)malloc(sizeof(int)*len);
    int i;
    int flag=0;
    for(i=0;i<len;i++)
    {
        printf("write a number: ");
        scanf("%d",&num[i]);
    }
    int key=7;
    int r=len;
    int l=0;
    int mid=(r+l)/2;
    while(l<=r)
    {
        mid=(r+l)/2;
        if(num[mid]==key)
        {
            flag=1;
            break;
        }
        if(key<num[mid])
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(flag==1)
    {
        printf("Key was found");
    }
}