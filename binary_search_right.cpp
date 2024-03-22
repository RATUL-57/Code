int binary_search(int *a,int n, int key)
{
    int left=0,right,mid;
    right=n-1;
    while(left<right)
    {
        if((left+right)%2)
            mid=(left+right)/2 + 1;
        else
            mid=(left+right)/2;
        if(a[mid]>key)
        {
            right=mid-1;
        }
        else
        {
            left=mid;
        }
    }
    if(a[right]==key)
        return right;
    else
        return -1;
}