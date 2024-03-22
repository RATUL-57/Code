#include <bits/stdc++.h>
using namespace std;

void addition_segment_tree(int index, int begin, int end);
void minimum_segment_tree(int index, int begin, int end);
void maximum_segment_tree(int index, int begin, int end);

int addition_query(int index, int begin, int end, int start_range, int end_range);
int minimum_query(int index, int begin, int end, int start_range, int end_range);
int maximum_query(int index, int begin, int end, int start_range, int end_range);

void update_addition_segment_tree(int index, int begin, int end, int start_range, int end_range, int value);
void update_minimum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value);
void update_maximum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value);

void lazy_update_of_addition_segment_tree(int index, int begin, int end, int start_range, int end_range, int value);
void lazy_update_of_minimum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value);
void lazy_update_of_maximum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value);

const int MX = 1e9+3, N = 1e6;
vector<int>given_input(N), segment_tree(4*N, 0), lazy_tree(4*N, 0);


int main()
{
    int n;
    cin >> n;

    given_input[0] = n;
    segment_tree[0] = n;
    lazy_tree[0] = n;

    for(int i=1; i<3*n; i++)
    {
        lazy_tree[i]=0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> given_input[i];
    }

    addition_segment_tree(1, 1, n);

    //lazy_update_of_addition_segment_tree(1,1,n,2,5,7);

    //cout << addition_query(1,1,n,4,4) << endl;

    // lazy_update_of_minimum_segment_tree(1, 1, n, 1, 5, 4);
    // lazy_update_of_minimum_segment_tree(1, 1, n, 2, 3, 1);

    for (int i = 1; i < 2 * n; i++)
        cout << segment_tree[i] << ' ';
    cout << endl;
}

void addition_segment_tree(int index, int begin, int end)
{
    if (begin == end)
    {
        segment_tree[index] = given_input[begin];
    }
    else
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int mid = (begin + end) / 2;

        addition_segment_tree(left, begin, mid);
        addition_segment_tree(right, mid + 1, end);

        segment_tree[index] = segment_tree[left] + segment_tree[right];
    }
}

void minimum_segment_tree(int index, int begin, int end)
{
    if (begin == end)
    {
        segment_tree[index] = given_input[begin];
    }
    else
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int mid = (begin + end) / 2;

        minimum_segment_tree(left, begin, mid);
        minimum_segment_tree(right, mid + 1, end);

        segment_tree[index] = min(segment_tree[left], segment_tree[right]);
    }
}

void maximum_segment_tree(int index, int begin, int end)
{
    if (begin == end)
    {
        segment_tree[index] = given_input[begin];
    }
    else
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int mid = (begin + end) / 2;

        maximum_segment_tree(left, begin, mid);
        maximum_segment_tree(right, mid + 1, end);

        segment_tree[index] = max(segment_tree[left], segment_tree[right]);
    }
}

int addition_query(int index, int begin, int end, int start_range, int end_range)
{
    if (begin > end_range || end < start_range)
    {
        return 0;
    }
    else if (begin >= start_range && end <= end_range)
    {
        return segment_tree[index];
    }
    else
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int mid = (begin + end) / 2;

        int a, b;

        a = addition_query(left, begin, mid, start_range, end_range);
        b = addition_query(right, mid + 1, end, start_range, end_range);

        return a + b;
    }
}

int minimum_query(int index, int begin, int end, int start_range, int end_range)
{
    if (begin > end_range || end < start_range)
    {
        return 999999999;
    }
    else if (begin >= start_range && end <= end_range)
    {
        return segment_tree[index];
    }
    else
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int mid = (begin + end) / 2;

        int a, b;

        a = minimum_query(left, begin, mid, start_range, end_range);
        b = minimum_query(right, mid + 1, end, start_range, end_range);

        return min(a, b);
    }
}

int maximum_query(int index, int begin, int end, int start_range, int end_range)
{
    if (begin > end_range || end < start_range)
    {
        return 0;
    }
    else if (begin >= start_range && end <= end_range)
    {
        return segment_tree[index];
    }
    else
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int mid = (begin + end) / 2;

        int a, b;

        a = maximum_query(left, begin, mid, start_range, end_range);
        b = maximum_query(right, mid + 1, end, start_range, end_range);

        return max(a, b);
    }
}

void update_addition_segment_tree(int index, int begin, int end, int start_range, int end_range, int value)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int mid = (begin + end) / 2;

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range && begin == end)
    {
        segment_tree[index] += value;
        return;
    }
    else
    {
        update_addition_segment_tree(left, begin, mid, start_range, end_range, value);
        update_addition_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = segment_tree[left] + segment_tree[right];
    }
}

void update_minimum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int mid = (begin + end) / 2;

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range && begin == end)
    {
        segment_tree[index] += value;
        return;
    }
    else
    {
        update_minimum_segment_tree(left, begin, mid, start_range, end_range, value);
        update_minimum_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = min(segment_tree[left],segment_tree[right]);
    }
}

void update_maximum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int mid = (begin + end) / 2;

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range && begin == end)
    {
        segment_tree[index] += value;
        return;
    }
    else
    {
        update_maximum_segment_tree(left, begin, mid, start_range, end_range, value);
        update_maximum_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = max(segment_tree[left],segment_tree[right]);
    }
}

void lazy_update_of_addition_segment_tree(int index, int begin, int end, int start_range, int end_range, int value)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int mid = (begin + end) / 2;

    if(lazy_tree[index] != 0)
    {
        segment_tree[index] += lazy_tree[index];
        if(begin != end)
        {
            lazy_tree[index*2] += lazy_tree[index];
            lazy_tree[index*2+1] += lazy_tree[index];
        }
        lazy_tree[index] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range)
    {
        segment_tree[index] += value*(end-begin+1);
        if(begin != end)
        {
            lazy_tree[index*2] += value;
            lazy_tree[index*2+1] += value;
        }
        return;
    }
    else
    {
        lazy_update_of_addition_segment_tree(left, begin, mid, start_range, end_range, value);
        lazy_update_of_addition_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = segment_tree[left] + segment_tree[right];
    }
}

void lazy_update_of_minimum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int mid = (begin + end) / 2;

    if(lazy_tree[index] != 0)
    {
        segment_tree[index] += lazy_tree[index];
        if(begin != end)
        {
            lazy_tree[index*2] += lazy_tree[index];
            lazy_tree[index*2+1] += lazy_tree[index];
        }
        lazy_tree[index] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range)
    {
        segment_tree[index] += value;
        if(begin != end)
        {
            lazy_tree[index*2] += value;
            lazy_tree[index*2+1] += value;
        }
        return;
    }
    else
    {
        lazy_update_of_minimum_segment_tree(left, begin, mid, start_range, end_range, value);
        lazy_update_of_minimum_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = min(segment_tree[left],segment_tree[right]);
    }
}

void lazy_update_of_maximum_segment_tree(int index, int begin, int end, int start_range, int end_range, int value)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int mid = (begin + end) / 2;

    if(lazy_tree[index] != 0)
    {
        segment_tree[index] += lazy_tree[index];
        if(begin != end)
        {
            lazy_tree[index*2] += lazy_tree[index];
            lazy_tree[index*2+1] += lazy_tree[index];
        }
        lazy_tree[index] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range)
    {
        segment_tree[index] += value;
        if(begin != end)
        {
            lazy_tree[index*2] += value;
            lazy_tree[index*2+1] += value;
        }
        return;
    }
    else
    {
        lazy_update_of_maximum_segment_tree(left, begin, mid, start_range, end_range, value);
        lazy_update_of_maximum_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = max(segment_tree[left],segment_tree[right]);
    }
}