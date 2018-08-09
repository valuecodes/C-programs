#include <stdio.h>
#define INPUT "C:\\Users\\Juha\\Desktop\\apple.txt"
#define DATA "C:\\Users\\Juha\\Desktop\\appledata.txt"
#define INPUTSTOCK "C:\\Users\\Juha\\Desktop\\applestock.txt"
#define STOCKSORTED "C:\\Users\\Juha\\Desktop\\applesorted.txt"
#define APPLESTOCK "C:\\Users\\Juha\\Desktop\\applesorted.txt"
typedef struct Stock
{
    
    int price[9][52][468];

}price;
typedef struct Stock
{
    int year[9];
    int price[468];

}STOCK;
typedef struct Company
{
    char name[9];
    int newline;
    int netSales[9];
    int costOfSales[9];
    int grossM[9];
    int rnd[9];
    int sga[9];
    int totalopex[9];
    int oprationIncome[9];
    int other[9];
    int incomebpfit[9];
    int provincome[9];
    int netIncome[9];

}COMPANY;
void printCompany(COMPANY *c);
void sortData();
void saveList(COMPANY *c);
void writeName();
void sortStock();
int main()
{
   
    writeName();
    sortData();
    // sortStock();
    COMPANY c;
    FILE *file=fopen(DATA,"r");
    if(file == NULL)
    {
        printf("Error opening a file...");
    }
    int len=0;
    int cnt=1;
    int i;
    int j;
    if(file==NULL)
    {
        printf("Error writing file...");
    }
    int n=0;
    for(i=0;i<10;i=i+3)
    {
        for(j=0;j<3;j++)
        {
            if(j==0)
            {
                fscanf(file,"\n%d\t",&c.netSales[i+j]);
            }
            else if(j==1)
            {
                fscanf(file,"%d\t",&c.netSales[i+j]);
            }
            else if(j==2)
            {
                fscanf(file,"%d\n",&c.netSales[i+j]);
            }   
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.costOfSales[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.costOfSales[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.grossM[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.grossM[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.rnd[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.rnd[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.sga[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.sga[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.totalopex[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.totalopex[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.oprationIncome[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.oprationIncome[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.other[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.other[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.incomebpfit[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.incomebpfit[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.provincome[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.provincome[i+j]);
            }
        }
        for(j=0;j<3;j++)
        {
            if(j==2)
            {
                fscanf(file,"%d\n",&c.netIncome[i+j]);
            }
            else
            {
                fscanf(file,"%d\t",&c.netIncome[i+j]);
            }
        }

    }
    
    fclose(file);
    
}
void sortData()
{
    FILE *file = fopen(INPUT,"r+");
    FILE *file1 = fopen(DATA,"a");
    
    if(file == NULL)
    {
        printf("Error opening a file...");
    }
    if(file1 == NULL)
    {
        printf("Error opening a file...");
    }
    int line=0;
    while(1)
    {
        char ch = fgetc(file);
        int n=ch;
        if(ch == EOF)
        {
            break;
        }
        if(ch=='\n')
        {
            line++;
        }

        if(line==1||line==3||line==5||line==9||line==11||line==13||line==15||line==17||line==19||line==21||line==23)
        {
        if(ch=='\n'||ch=='-')
        {
            printf("%c",ch);
            putc(ch,file1);
        }
        if(n>=48&&n<=57)
        {
            printf("%d",n-48);
            putc(ch,file1);
        }
        if(ch=='\t')
        {
            putc(ch,file1);
        }
        }
        if(line==24)
        {
            line=0;
        }
    }
    fclose(file);
    fclose(file1);
}

void writeName()
{
    COMPANY c;
    FILE *file = fopen(DATA,"a");
    printf("Write company name:");
    scanf("%s",c.name);
    fprintf(file,"%s",c.name);
    fclose(file);
}