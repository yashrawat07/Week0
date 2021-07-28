#include<iostream>
using namespace std;
int main()
{
    int arr[20],comp=0,i,n,p=0;
    cout<<"Enter the range"<<endl;
    cin>>n;
    cout<<"Enter the elements of array"<<endl;
    for(i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key element"<<endl;
    cin>>key;
    for(i=0;i<=n-1;i++)
    {
        comp++;
        if(key==arr[i])
        {
            p++;
            break;
        }
    }
    if(p!=0)
    {
        cout<<key<<" found successfully"<<endl;
        cout<<"Number of comparisons required is "<<comp<<endl;
    }
    else
    {
        cout<<key<<" was not found"<<endl;
        cout<<"Number of comparisons required is "<<n<<endl;
    }
    return 0;
}
