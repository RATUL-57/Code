#include <bits/stdc++.h>
using namespace std;

class HEAP
{
    public:
        int heapsize;
        int left;
        int right;
        int parent;
        int position;
        vector<int>heap;
        
        void fix_max_heap(int pos);
        void build_max_heap();
        void fix_min_heap(int pos);
        void build_min_heap();
        void heap_sort_ascending();
        void heap_sort_descending();
        void fix_sort_max_heap(int pos, int temp);
        void fix_sort_min_heap(int pos, int temp);
        int max_priority_queue();
        int min_priority_queue();
        void extract_min_value();
        void extract_max_value();
        void insert_min_heap(int num);
        void insert_max_heap(int num);
        void min_heap_increase_by_key(int pos, int key);
        void min_heap_decrease_by_key(int pos, int key);
        void max_heap_increase_by_key(int pos, int key);
        void max_heap_decrease_by_key(int pos, int key);
};

void HEAP::max_heap_decrease_by_key(int pos, int key)
{
    build_max_heap();
    heap[pos] -= key;
    fix_max_heap(pos);
}

void HEAP::min_heap_increase_by_key(int pos, int key)
{
    build_min_heap();
    heap[pos] += key;
    fix_min_heap(pos);
}

void HEAP::max_heap_increase_by_key(int pos, int key)
{
    build_max_heap();
    heap[pos] += key;
    while(1)
    {
        parent = (pos-1)/2;
        if(heap[pos]<=heap[parent])
            break;
        else
        {
            swap(heap[pos],heap[parent]);
            pos = parent;
        }
    }
}

void HEAP::min_heap_decrease_by_key(int pos, int key)
{
    build_min_heap();
    heap[pos] -= key;
    while(1)
    {
        parent = (pos-1)/2;
        if(heap[pos]>=heap[parent])
            break;
        else
        {
            swap(heap[pos],heap[parent]);
            pos = parent;
        }
    }
}

void HEAP::insert_min_heap(int num)
{
    build_min_heap();
    heap.push_back(num);
    position = heap.size()-1;
    while(1)
    {
        parent = (position-1)/2;
        if(heap[position]>=heap[parent])
            break;
        else
        {
            swap(heap[position],heap[parent]);
            position = parent;
        }
    }
}

void HEAP::insert_max_heap(int num)
{
    build_max_heap();
    heap.push_back(num);
    position = heap.size()-1;
    while(1)
    {
        parent = (position-1)/2;
        if(heap[position]<=heap[parent])
            break;
        else
        {
            swap(heap[position],heap[parent]);
            position = parent;
        }
    }
}

void HEAP :: extract_min_value()
{
    build_min_heap();
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    fix_min_heap(0);
}

void HEAP :: extract_max_value()
{
    build_max_heap();
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    fix_max_heap(0);
}

int HEAP :: min_priority_queue()
{
    build_min_heap();
    return heap[0];
}

int HEAP :: max_priority_queue()
{
    build_max_heap();
    return heap[0];
}

void HEAP :: fix_max_heap(int pos)
{
    int largest;
    left = 2*pos+1;
    right = 2*pos+2;
    // cout << left << endl << right << endl;
    if(left<heap.size() && heap[left]>heap[pos])
    {
        largest = left;
    }
    else
    {
        largest = pos;
    }
    if(right<heap.size() && heap[largest] < heap[right])
    {
        largest = right;
    }
    if(largest!=pos)
    {
        swap(heap[pos],heap[largest]);
        fix_max_heap(largest);
    }
} 

void HEAP :: build_max_heap()
{
    for(int i=(heap.size()/2)-1;i>=0;i--)
    {
        fix_max_heap(i);
    }
}

void HEAP :: fix_min_heap(int pos)
{
    int lowest;
    left = 2*pos+1;
    right = 2*pos+2;
    // cout << left << endl << right << endl;
    if(left<heap.size() && heap[left]<heap[pos])
    {
        lowest = left;
    }
    else
    {
        lowest = pos;
    }
    if(right<heap.size() && heap[lowest] > heap[right])
    {
        lowest = right;
    }
    if(lowest!=pos)
    {
        swap(heap[pos],heap[lowest]);
        fix_min_heap(lowest);
    }
}

void HEAP :: build_min_heap()
{
    for(int i=(heap.size()/2)-1;i>=0;i--)
    {
        fix_min_heap(i);
    }
}

void HEAP :: heap_sort_ascending()
{
    build_max_heap();
    int temp=heap.size()-1;
    for(int i=temp;i>=0;i--)
    {
        swap(heap[i],heap[0]);
        fix_sort_max_heap(0,i);
    }
}

void HEAP :: heap_sort_descending()
{
    build_min_heap();
    int temp=heap.size()-1;
    for(int i=temp;i>=0;i--)
    {
        swap(heap[i],heap[0]);
        fix_sort_min_heap(0,i);
    }
}

void HEAP :: fix_sort_max_heap(int pos, int temp)
{
    int largest;
    left = 2*pos+1;
    right = 2*pos+2;
    if(left<temp && heap[left]>heap[pos])
    {
        largest = left;
    }
    else
    {
        largest = pos;
    }
    if(right<temp && heap[largest] < heap[right])
    {
        largest = right;
    }
    if(largest!=pos)
    {
        swap(heap[pos],heap[largest]);
        fix_sort_max_heap(largest,temp);
    }
}

void HEAP :: fix_sort_min_heap(int pos, int temp)
{
    int lowest=pos;
    left = 2*pos+1;
    right = 2*pos+2;
    // cout << left << endl << right << endl;
    if(left<temp && heap[left]<heap[lowest])
    {
        lowest = left;
    }
    else
    {
        lowest = pos;
    }
    if(right<temp && heap[right]<heap[lowest])
    {
        lowest = right;
    }
    if(lowest!=pos)
    {
        swap(heap[pos],heap[lowest]);
        fix_sort_min_heap(lowest,temp-1);
    }
}

int main()
{
    HEAP a;
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        a.heap.push_back(temp);
    }
    // a.build_min_heap();
    // for(int i=0;i<n;i++)
    //    cout << a.heap[i] << ' ';
    // cout << endl << endl << endl;
    // a.build_max_heap();
    // for(int i=0;i<n;i++)
    //    cout << a.heap[i] << ' ';
    // cout << endl;
    // a.heap_sort_descending();
    // for(int i=0;i<n;i++)
    //    cout << a.heap[i] << ' ';
    // cout << endl;
    a.max_heap_increase_by_key(5,233);
    for(int i=0;i<a.heap.size();i++)
       cout << a.heap[i] << ' ';
    cout << endl;
}