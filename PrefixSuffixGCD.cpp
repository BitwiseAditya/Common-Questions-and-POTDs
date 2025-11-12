/*Assume you are given two arrays original and discount.
You can swap the contents of original[i] and discount[i]
for any one and only one index out of 0 to n-1. You have
to find the maximum value of GCD of all the original array
elements given you can do as told earlier. What is the maximum
GCD you can make.*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b)
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<ll> original(n), discount(n);
    for (int i = 0; i < n; ++i)
        cin >> original[i];
    for (int i = 0; i < n; ++i)
        cin >> discount[i];

    // prefix and suffix gcds
    vector<ll> prefix(n), suffix(n);
    prefix[0] = original[0];
    for (int i = 1; i < n; ++i)
        prefix[i] = gcdll(prefix[i - 1], original[i]);
    suffix[n - 1] = original[n - 1];
    for (int i = n - 2; i >= 0; --i)
        suffix[i] = gcdll(suffix[i + 1], original[i]);

    ll g0 = prefix[n - 1]; // gcd if we don't swap at all
    ll ans = g0;

    for (int i = 0; i < n; ++i)
    {
        ll g_except_i;
        if (n == 1)
        {
            // no other elements remain, gcd of empty set -> treat as 0
            g_except_i = 0;
        }
        else if (i == 0)
        {
            g_except_i = suffix[1];
        }
        else if (i == n - 1)
        {
            g_except_i = prefix[n - 2];
        }
        else
        {
            g_except_i = gcdll(prefix[i - 1], suffix[i + 1]);
        }
        ll g_after_swap = gcdll(g_except_i, discount[i]);
        ans = max(ans, g_after_swap);
    }

    cout << ans << '\n';
    return 0;
}
