#include<stdio.h>
#include<ctype.h>

void FIRST(char[],char );
void addToResultSet(char[],char);
int numOfProductions;
char productionSet[10][10];
void main()
{
    int i, choice;
    char c;
    char result[20];
    printf("Enter the number of production req :");
    scanf(" %d",&numOfProductions);
    for(i=0;i<numOfProductions;i++)//read production string eg: E=E+T
    {
        printf("Enter productions Number %d : ",i+1);
        scanf(" %s",productionSet[i]);
    }
        printf("\n");
        for(i=0;i<numOfProductions;i++)
    {
        printf("The productions Rule is  %d : %s\n",i+1,productionSet[i]);
        printf("\n");
    }
    

    do
    {
        printf("\n Find the FIRST of  :");
        scanf(" %c",&c);
        FIRST(result,c);
        printf("\n FIRST(%c)= { ",c);
        for(i=0;result[i]!='\0';i++)
        printf(" %c ",result[i]);    
        printf("}\n");
         printf("Enter 1 to exit or else to continue:\t");
        scanf(" %d",&choice);
    }
    while(choice != 1);
}

void FIRST(char* Result,char c)
{
    int i,j,k;
    char subResult[20];
    int foundEpsilon;
    subResult[0]='\0';
    Result[0]='\0';
    //If X is terminal, FIRST(X) = {X}.
    //Checking for terminal.
    if(!(isupper(c)))
    {
        addToResultSet(Result,c);
               return ;
    }
    //If X is non terminal
    //Read each production
    for(i=0;i<numOfProductions;i++)
    {
    //Find production with X as LHS
        if(productionSet[i][0]==c)
        {
    //If X → e is a production, then add e to FIRST(X).
 	if(productionSet[i][2]=='e') addToResultSet(Result,'e');
            //If X is a non-terminal, and X → Y1 Y2 … Yk
            //is a production, then add a to FIRST(X)
            //if for some i, e is in FIRST(Yi),
            //and e is in all of FIRST(Y1), …, FIRST(Yi-1).
      else{
                j=2;
                while(productionSet[i][j]!='\0'){
                foundEpsilon=0;
                FIRST(subResult,productionSet[i][j]);
                for(k=0;subResult[k]!='\0';k++)
                    addToResultSet(Result,subResult[k]);
                 for(k=0;subResult[k]!='\0';k++)
                     if(subResult[k]=='e'){
                         foundEpsilon=1;
                         break;
                     }
                 //No e found, no need to check next element
                 if(!foundEpsilon)
                     break;
                 j++;
                }
            }
    }
}
    return ;
}

void addToResultSet(char Result[],char val)
{
    int k;
    for(k=0 ;Result[k]!='\0';k++)
        if(Result[k]==val)
            return;
    Result[k]=val;
    Result[k+1]='\0';
} 	