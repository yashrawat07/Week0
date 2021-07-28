#include<iostream>
using namespace std;
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
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the elements of array"<<endl;
	while(i<n)
	{
		cin>>arr[i];
		i++;
	}
	cout<<"Enter the element to be searched"<<endl;
	cin>>ele;
	n = binsearch(arr,0,n,ele);
	if(n == -1)
	{
		cout<<"Element not found"<<endl;
		return 0;
	}
	cout<<"Element "<<ele<<" found at index "<<n<<endl;;
	return 0;
}
