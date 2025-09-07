#include <bits/stdc++.h>
using namespace std;
int main()
{
    auto cmp = [](const pair<double, int> &a, const pair<double, int> &b)
    {
        return a.first > b.first;
    };
    set<pair<double, int>, decltype(cmp)> st(cmp);
    st.insert({2, 4});
    st.insert({3, 1});
    st.insert({4, 1});
    for (const auto &nums : st)
    {
        cout << nums.first << " " << nums.second << endl;
    }
    st.insert({3.55, 1});
    cout << "after inserting 3.55,1" << endl;
    for (const auto &nums : st)
    {
        cout << nums.first << " " << nums.second << endl;
    }
    return 0;
}
