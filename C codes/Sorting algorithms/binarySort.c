#include <stdio.h>
#include <stdlib.h>
void getnum(int len,int *num);
void bsort(int len,int *num);
int main()
{
    int len;
    printf("Write how many numbers you want: ");
    scanf("%d",&len);
    int i,j,temp;
    int *num;
    num = (int*) malloc(len * sizeof(int));
    if(num == NULL)
    {
        printf("Error! Memory not allocated");
        exit(0);
    }
    getnum(len,num);
    bsort(len,num);
    
    for(i=0;i<len;i++)
    {
        printf("%d\n",num[i]);
    }
}

void getnum(int len,int *num)
{   
    int i;
    for(i=0;i<len;i++)
    {
        printf("Write a number(%d): ",i);
        scanf("%d",num+i);
    }
}
void bsort(int len,int *num)
{   
    int i,j,temp;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1;j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
}