#include <bits/stdc++.h>
using namespace std;
void insert_at_heap(vector<int> &v, int x)
{
    v.push_back(x);
    int cur_ind = v.size() - 1;
    while (cur_ind != 0)
    {
        int prrent = (cur_ind - 1) / 2;
        if (v[prrent] < v[cur_ind])
            swap(v[prrent], v[cur_ind]);
        else
            break;
        cur_ind = prrent;
    }
}
void delet_at_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    while (true)
    {
        int left_idx = cur * 2 + 1;
        int right_idx = cur * 2 + 2;
        int last_idx = v.size() - 1;
        if (left_idx <= last_idx && right_idx < last_idx)
        {
            if (v[left_idx] >= v[right_idx] && v[left_idx] > v[cur])
            {
                swap(v[left_idx], v[cur]);
                cur=left_idx;
            }
            else if (v[right_idx] >= v[left_idx] && v[right_idx] > v[cur])
            {
                swap(v[right_idx], v[cur]);
                cur=right_idx;
            }
            else
                break;
        }
        else if (left_idx <= last_idx)
        {
            if (v[left_idx] > v[cur])
            {
                swap(v[left_idx], v[cur]);
                cur=left_idx;
            }
            else
                break;
        }
        else if (right_idx <= last_idx)
        {
            if (v[right_idx]>v[cur])
            {
                swap(v[right_idx], v[cur]);
                right_idx = cur;
            }
            else
                break;
        }
        else
            break;
    }
}
void print_heap(vector<int>v)
{
    for (int val : v)
    {
        cout << val << " ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_at_heap(v, x);
    }
    delet_at_heap(v);
    print_heap(v);
    return 0;
}