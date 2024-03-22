#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *a, int start, int end, int key, int prevmid)
{
    int mid, i, j;
    mid = (start + end) / 2;
    if(prevmid==mid)
        return -1;
    else
        prevmid=mid;
    if(a[end]==key)
        return end;
    else if (a[mid] == key)
    {
        //cout << mid << " ";
        return mid;
    }
    else if (a[mid] < key)
    {
        //cout << mid << " ";
        return binarySearch(a, mid, end, key, prevmid);
    }
    else if (a[mid] > key)
    {
        //cout << mid << " ";
        return binarySearch(a, start, mid, key, prevmid);
    }
    else
        return -1;
}

int main()
{
    int n, i, j;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> j;
        
    }
}


