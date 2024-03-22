#include <bits/stdc++.h>
using namespace std;

int front=0,rear=0,s=0;

void enqueue(int * arr, int x)
{
    arr[rear]=x;
    rear++;
}

void dequeue(int * arr)
{
    if(front==rear)
        cout << "Empty" << endl;
    else
        front++;
}


int main()
{

}