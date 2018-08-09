#include <stdio.h>
void xe();

//Program that prints X visualized
//Write how big X you want(5-50)

int main()
{
    int a;
    printf("Write size of X (5-50): ");
    scanf("%d",&a);
    if (a<5 || a>50)
        if(a<5)
        {
            printf("X is below 5");
        }
        else
        {
            printf("X over 50");
        }
    else 
        {       
            printf("\n\n");
            xe(a);
        }
}

void xe(int b)
{
    int i;
    i=b;
    {
    int a,b,c,d,f,g;
    for(a=0;a<i;a++)
    {
        for(b=0;b<a;b++)
        {
            printf("| ");
        }
        for(c=i;c>a;c--)
        {
            if (c==i)
            {
                printf("    ");
            }
            printf("- ");
        }
        for(d=i;d>a;d--)
        {
            if (d==a+1)
            {
                printf("    ");
            }
            else
            {
            printf("- ");
            }   
        }
        for(f=0;f<a;f++)
        {
            printf("| ");
        }
        
        printf("\n");
    }
    for(a=0;a<i;a++)
    {
        for(b=i;b>a;b--)
        {
            printf("| ");
        }
        for(c=0;c<=a;c++)
        {
            if (c==0)
            {
                printf("    ");
            }
            else
            {
            printf("- ");
            }
        }
        for(d=1;d<=a;d++)
        {
            if (d==a)
            {
                printf("  ");
            }
            else
            {
            printf("- ");
            } 
        }
        for(f=i+1;f>a;f--)
        {
            if(f==i+1)
            {
            printf("  ");
            }
            else
            printf("| ");
        }
    printf("\n");
    }
}
}