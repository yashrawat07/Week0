#include<stdio.h>
int binsearch(int arr[],int F,int L,int ele)
{
	if(F<L)
	{
		int mid = (F+L)/2;
		if(arr[mid] == ele)
		return mid;
		else if(arr[mid]>ele)
		binsearch(arr,F,mid-1,ele);
		else if(arr[mid]<ele)
		binsearch(arr,mid+1,L,ele);
	}
	else if(F==L)
	return -1;
}
int main()
{
	int n,i,ele;
	int arr[100];
	printf("\n\tEnter the number of elements : ");
	scanf("%d",&n);
	printf("\n\tEnter the array :\n");
	while(i<n)
	{
		printf("\t");
		scanf("%d",&arr[i]);
		i++;
	}
	printf("\n\tEnter element to be searched : ");
	scanf("%d",&ele);
	n = binsearch(arr,0,n,ele);
	if(n == -1)
	{
		printf("\n\tElement not found\n");
		getch();
		return 0;
	}
	printf("\n\tElement %d found at index %d",ele,n);
	return 0;
}
