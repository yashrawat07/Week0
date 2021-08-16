#include <iostream>
using namespace std;
int binary_search(int a[], int n, int key, int flag)
{
    int l, r, mid, result = -1;
    l = 0, r = n - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == key)
        {
            result = mid;
            if (flag == 1)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        else if (key < a[mid])
            r = mid -1;
        else
            l = mid + 1;
    }
    return result;
}
int main()
{
    int t, i, j, n, key, first, last;
    cin >> t;
    while (t)
    {
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> key;
        first = binary_search(a, n, key, 1);
        if (first == -1)
            cout << key << " - 0"<<endl;
        else
        {
            last = binary_search(a, n, key, 0);
            cout << key << " - " << last - first + 1<<endl;
        }
        t--;
    }
    return 0;
}
