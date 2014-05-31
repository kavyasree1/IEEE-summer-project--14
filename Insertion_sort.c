#include<stdio.h>
int main()
{int i,n,A[5000];
void insertion_sort(int[],int);
printf("Enter the no. of elements: ");
scanf("%d",&n);
printf("\nEnter the elements:\n");	
for(i=0;i<n;i++)
scanf("%d",&A[i]);
insertion_sort(A,n);
printf("\nThe sorted array is:\n");
for(i=0;i<n;i++)
printf("%d ",A[i]);
return(0);
}

void insertion_sort(int A[],int n)
{int num,i,j;
 for(i=0;i<n;i++)
	{
		num=A[i];
		j=i;
		while(j>0 && A[j-1]>num)
		{
			
			A[j]=A[j-1];
			j--;
			A[j]=num;
		}
}
}
