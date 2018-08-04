#include <stdio.h>

typedef struct Person
{
    char name[20];
    int weight;
    int height;
}PERSON;

void addPersonDetail(PERSON *p1,int *cnt);
PERSON WritePersonDetail();
void printPersonDetail(PERSON p1);
void printAll(PERSON *p1,int cnt);
void change(PERSON *p1);
void menu(PERSON *p1,int *cnt);
void personname(PERSON p1,int n);

int main()
{
    PERSON p1[10];
    int cnt=0;
    printf("Write person details\n\n");
    addPersonDetail(p1,&cnt);
    printAll(p1,cnt);
    menu(p1,&cnt);
    
}

void menu(PERSON *p1,int *cnt)
{
    int ans=0;
    char dummy;
    while(ans==0)
    {
        printf("\n\nWrite 1 to modify person details\nWrite 2 to add person\nWrite 3 to print all data\nWrite 4 to exit\n");
        scanf("%d",&ans);
        scanf("%c",&dummy);
        if(ans==1)
        {
            int opt;
            printf("Which person details you want to change");
            int i;
            for(i=0;i<*cnt;i++)
            {
                personname(p1[i],i);
            }
            scanf("%d",&opt);
            if(opt<*cnt)
            {
                change(&p1[opt]);
            }

        }
        else if(ans==2)
        {
            addPersonDetail(p1,cnt);
            printAll(p1,*cnt); 
        }
        else if(ans==3)
        {
            printAll(p1,*cnt);      
        }
        else if(ans==4)
        {
            printf("Exiting...");
            break;
        }
        else
        {
            ans=0;
        }
    ans=0;
    }

}

void personname(PERSON p1,int n)
{
    printf("\nPress %d to change %s details",n,p1.name);
}

void addPersonDetail(PERSON *p1,int *cnt)
{
    char ans='y';
    int i;
    char dummy;
    while(ans=='y' || ans=='Y')
    {
        p1[*cnt]=WritePersonDetail();
        scanf("%c",&dummy);
        printf("Do you want to put another person details(y/n)");
        scanf("%c",&ans);
        scanf("%c",&dummy);
        *cnt=*cnt+1;
    }
}

void printAll(PERSON *p1,int cnt)
{
    int i;
    printf("\nList of all person: ------");
    for(i=0;i<cnt;i++)
    {
        printPersonDetail(p1[i]);  
    }
    printf("--------------------------");
}

PERSON WritePersonDetail()
{
    PERSON p1;
    printf("Write person name: ");
    gets(p1.name);
    printf("Write person weight: ");
    scanf("%d",&p1.weight);
    printf("Write person height: ");
    scanf("%d",&p1.height);
    return p1;
}

void change(PERSON *p1)
{
    int opt;
    char dummy;
    printf("\nPress 1 to change name\nPress 2 to change weight\nPress 3 to change height\nPress 4 to make no changes");
    scanf("%d",&opt);
    scanf("%c",&dummy);
    if(opt==1)
    {
        printf("\nWrite a new name");
        gets(p1->name);
    }
    if(opt==2)
    {
        printf("\nWrite a new weight");
        scanf("%d",&p1->weight);
    }
    else if(opt==3)
    {
        printf("\nWrite a new height");
        scanf("%d",&p1->height);
    }
    else if(opt==4)
    {
        printf("No changes made");
    }
    else
    {
        printf("No changes made");
    }
    
}

void printPersonDetail(PERSON p1)
{
    printf("\nName: %s\nWeight: %d\nHeight: %d\n",p1.name,p1.weight,p1.height);
}