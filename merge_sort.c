#include<stdio.h>
void ins_sort(int A[],int left,int right)
{int num,i,j;
	for(i=left;i<=right;i++)
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
void merge(int A[],int left,int mid, int right)
{int i,j,k=left,n1,n2,L[5000],R[5000];
	n1=mid-left+1;
	n2=right-mid;
	for(i=0;i<n1;i++)
	L[i]=A[left+i];
	for(j=0;j<n2;j++)
	R[j]=A[mid+j+1];
	i=0;
	j=0;
	while(i<n1&&j<n2)
	{		
	if(L[i]<=R[j])
	{
		A[k]=L[i];
		i++;k++;
	}
	else
	{   A[k]=R[j];
		j++;k++;
		}
    }
    if(i==n1)
    for(;j<n2;j++,k++)
    	A[k]=R[j];
    else
    for(;i<n1;i++,k++)
        A[k]=L[i];
}
void partition(int A[],int left,int right)
{int mid;
if(right-left<15)
ins_sort(A,left,right);
else
	if(left<right)
	{
		mid=(left+right)/2;
		partition(A,left,mid);
		partition(A,mid+1,right);
		merge(A,left,mid,right);
	}
}

int main()
{int i,n,A[5000];
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	partition(A,0,n-1);
	printf("\nThe elements of the sorted array are:\n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
return(0);
}

