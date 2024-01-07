#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        int cur_ind=v.size()-1;
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
    // cout<<cur_ind<<endl;
    // cout<<v.size()<<endl;

    for (int val : v)
        cout << val << " ";

    return 0;
}