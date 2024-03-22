int primeChecker(long long n)
{
    int i;
    long long k=sqrt(n);
    if(n==2 || n==3)
        return 1;
    else if(n%2==0)
        return 0;
    else if(n%3==0)
        return 0;
    for(i=5;i<=k;i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
