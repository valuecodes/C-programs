#include <stdio.h>
#include <stdlib.h>

void bub(int *num, int len);

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
    bub(num,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n",num[i]);
    }
}

void bub(int *num, int len)
{
    int i,jlen=len,j;
    int nlen=0;
    int tmp;
    int max;
    int swap=0;
    int cnt=0;
    int r=len;
    for(i=0;i<len;i++)
    {
        swap=0;
        for(j=0;j<jlen;j++)
        {
            if(num[j]>num[j+1])
            {
                tmp=num[j];
                num[j]=num[j+1];
                num[j+1]=tmp;    
                swap++;
                if(num[j]>max)
                {
                    num[len]=max;
                    jlen++;
                }
                cnt++;
            }
        }
        
        jlen--;
        if(swap==0)
        {
            printf("\nNumber of swaps: %d\n",cnt);
            break;
        }
    }
}