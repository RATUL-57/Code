#include <bits/stdc++.h>
using namespace std;

int binary_search(int *a,int n, int key)
{
    int left=0,right,mid;
    right=n-1;
    while(left<right)
    {
        mid=(left+right)/2;
        if(a[mid]<key)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    if(a[left]==key)
        return left;
    else
        return -1;
}

int main()
{
    int n, i, j, k;
    cin >> n >> k;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
       cout << a[i] << ' ';
    cout << endl;
    cout << binary_search(a,n,k);
}