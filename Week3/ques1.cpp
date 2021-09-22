#include<iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
  int comps=0, shifts=0;
  int i, j, key;
  for(i=1; i<n; i++)
  {
    key = arr[i];
    j=i-1;
    while(j>=0 && key<arr[j])
    {
      arr[j+1] = arr[j];
      j--;
      shifts++;
      comps++;
    }
    arr[j+1] = key;
    shifts++;
  }
  for(i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<"\ncomparisons = "<<comps<<endl<<"shifts = "<<shifts<<endl;
}
int main()
{
  int t,n,i;
  cout<<"Enter the number of test cases"<<endl;
  cin>>t;
  while(t--)
  {
  	cout<<"Enter the range"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array"<<endl;
    for(i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    insertion_sort(arr,n);
  }
  return 0;
}
