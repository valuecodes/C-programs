#include <stdio.h>

void Print(int n[][4]);
int printRight(int n[][4],int ro);
int printDown(int n[][4],int ro);
int printLeft(int n[][4],int ro);
int printUp(int n[][4],int ro);
int main()
{
    // int n[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n[4][4]={{2,4,6,8},{5,9,12,16},{2,11,5,9},{3,2,1,8}};
    // Print(n);
    int ro=0;
    int cnt=0;
    int total;
    while(1)
    {
    cnt=printRight(n,ro);
    total=total+cnt;
    if(total==2)
    {
        break;
    }
    ro++;
    cnt=printDown(n,ro);
    total=total+cnt;
    if(total==2)
    {
        break;
    }
    cnt=printLeft(n,ro);
    total=total+cnt;
    if(total==2)
    {
        break;
    }
    cnt=printUp(n,ro);
    total=total+cnt;
    if(total==2)
    {
        break;
    }
    }
    // printf("\n\n%d",total);
}

int printRight(int n[][4],int ro)
{
    int i;
    int j=ro;
    int cnt=0;
    for(i=ro;i<4-ro;i++)
    {
        printf("%d ",n[j][i]);
        cnt++;
    }
    if(cnt==1)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
}
int printDown(int n[][4],int ro)
{
    int j=3-ro+1;
    int i;
    int cnt=0;
    for(i=ro;i<4-ro+1;i++)
    {
        printf("%d ",n[i][j]);
        cnt++;
    }
    if(cnt==1)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
}
int printLeft(int n[][4],int ro)
{
    int j=3-ro+1;
    int i;
    int cnt=0;
    for(i=3-ro;i>=ro-1;i--)
    {
        printf("%d ",n[j][i]);
        cnt++;
    }
    if(cnt==1)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
}
int printUp(int n[][4],int ro)
{
    int j=ro-1;
    int i;
    int cnt=0;
    for(i=3-ro;i>=ro;i--)
    {
        printf("%d ",n[i][j]);
        cnt++;
    }
    if(cnt==1)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
}


void Print(int n[][4])
{   
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",n[i][j]);
        }
    }
}