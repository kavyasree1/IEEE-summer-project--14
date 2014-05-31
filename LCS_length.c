#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    return(a>b?a:b);
}

int lcs(char *A,char *B)
{
    int m, n, i, j, LCS[100][100];

    m=strlen(A);
    n=strlen(B);

    for(i=0;i<=m;i++)
        LCS[i][0]=0;
    for(j=0;j<=n;j++)
        LCS[0][j]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);

        }
    }

    return(LCS[m][n]);
}

int main()
{
    char A[100], B[100];

    printf("Enter two strings: \n First string: ");
    gets(A);
    printf("\nSecond string: ");
    gets(B);
    printf("The longest commong subsequence is of length %d ",lcs(A,B));

    return(0);
}
