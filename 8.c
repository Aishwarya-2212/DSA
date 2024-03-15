



#include <stdio.h>
#define max 25
int main()
{
    int a[max];
    FILE *input,*output;
    input=fopen("input.txt","r");
    if(input==NULL)
    {
        perror("\nError in opening a file\n");
        return 1;
    }
int i=0;

    while(!feof(input))
    {
        fscanf(input,"%d",&a[i]);
        i++;
    }
int k,j;
    for(k=1;k<=4;k++)
    {
        for(j=1;j<=k;j++)
        {
        printf("* ");
        }
        printf("\n");
    }

    output=fopen("output.txt","w");


    fclose(output);
    return 0;
}

