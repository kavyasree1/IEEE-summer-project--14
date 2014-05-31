#include<stdio.h>
int merge(int A[],int left,int mid, int right)
{int i,j,k=left,n1,n2,no_inv=0,L[5000],R[5000];
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
	{no_inv+=n1-i;
		A[k]=R[j];
		j++;k++;
		}
    }
    if(i==n1)
    for(;j<n2;j++,k++)
    A[k]=R[j];
    else if(j==n2)
    for(;i<n1;i++,k++)
    A[k]=L[i];
    return(no_inv);
}
int partition(int A[],int left,int right)
{int mid,no_inv=0;
	if(left<right)
	{
		mid=(left+right)/2;
		no_inv+=partition(A,left,mid);
		no_inv+=partition(A,mid+1,right);
		no_inv+=merge(A,left,mid,right);
	}
	return(no_inv);
}

int main()
{int i,n,no_inv,A[5000];
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	no_inv=partition(A,0,n-1);
	printf("\nThe elements of the sorted array are:\n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\nInversion count= %d",no_inv);
return(0);
}

