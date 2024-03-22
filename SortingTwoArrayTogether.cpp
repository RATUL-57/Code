void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sortTwoArray(int *a, int *b,  int n)
{
    int i, j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                swap(&b[j],&b[j+1]);
            }
                
        }
    }
}