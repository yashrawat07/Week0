#include<stdio.h>
int QC(int arr[],int F,int L)
{
	int i,temp;
	int p = arr[L];
	int j = F-1;
	for(i = F;i<L;i++)
	{
		if(arr[i]<=p)
		{
			j++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[L];
	arr[L] = arr[j+1];
	arr[j+1] = temp;
	return j+1;
}
void QD(int arr[], int F, int L)
{
	int i;
	if(F<L)
	{
		int ind = QC(arr,F,L);
		QD(arr,F,ind-1);
		QD(arr,ind+1,L);
	}
}
int main()
{
	int arr[100],i,n;
	printf("\nFor only 1 Test Case\nEnter no. of elements:\n");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	QD(arr,0,n-1);
	printf("\n");
	printf("Elements after sorting:-");
	for(i=0;i<n;i++)
	{
		
		printf("%d ",arr[i]);
	}
	return 0;
}
